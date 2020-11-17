#pragma once

#include <iterator>

template<class T>
class circular_buffer {
public:
    class iter : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        T *p;
    public:

        iter() : p(nullptr) {}

        iter(T *p) : p(p) {}

        iter(const iter &it) : p(it.p) {}

        iter &operator+=(T x) {
            p += x;
            return *this;
        }

        iter &operator-=(T x) {
            p -= x;
            return *this;
        }

        iter operator++() {
            p++;
            return *this;
        }

        iter &operator--() {
            p--;
            return *this;
        }

        iter operator++(T) {
            iter tmp(*this);
            ++p;
            return tmp;
        }

        iter operator--(T) {
            iter tmp(*this);
            --p;
            return tmp;
        }

        auto operator-(const iter &it) {
            return (p - it.p);
        }

        iter operator+(int x) {
            return iter(p + x);
        }

        iter operator-(int x) {
            return iter(p - x);
        }

        T &operator*() const {
            return *p;
        }

        T *operator->() const {
            return p;
        }

        T &operator[](const int x) {
            return p[x];
        }

        bool operator==(const iter &x) const {
            return x.p == this->p;
        }

        bool operator!=(const iter &x) const {
            return x.p != this->p;
        }

        bool operator<(const iter &x) const {
            return x.p < this->p;
        }

        bool operator>(const iter &x) const {
            return x.p > this->p;
        }

        bool operator>=(const iter &x) const {
            return x.p >= this->p;
        }

        bool operator<=(const iter &x) const {
            return x.p <= this->p;
        }
    };

public:
    circular_buffer() = default;

    circular_buffer(int cap) : cap(cap) {
        head = 0;
        tail = 0;
        data = new T[cap];
    }

    ~circular_buffer() {
        delete[] data;
    }

    iter begin() const {
        return iter(data + head);
    }

    iter end() const {
        return iter(data + tail);
    }

    T &front() const {
        return data[head];
    }

    T &back() const {
        return data[tail - 1];
    }

    T &operator[](int index) {
        return data[index % cap];
    }

    void push_front(const T &x) {
        if (tail == cap) {
            data[head] = x;
            return;
        }
        for (int i = tail; i >= head; i--) {
            data[i + 1] = data[i];
        }
        data[head] = x;
        tail++;
    }

    void pop_front() {
        data[head] = 0;
        head++;
    }

    void push_back(const T &x) {
        if (tail == cap) tail--;
        if (tail == cap + 1) tail -= 2;
        data[tail] = x;
        if (tail != cap + 1) tail++;
    }

    void pop_back() {
        data[tail] = 0;
        tail--;
    }

    void resize(const int &n) {
        T *tmp = new T[n];
        for (int i = 0; i < n; i++)
            tmp[i] = i < cap ? data[i] : 0;
        delete[] data;
        data = tmp;
        cap = n;
    }

    void push_in_place(iter it, T x) {
        for (auto i = iter(data + tail); i != it - 1; i--) {
            *(i + 1) = *i;
        }
        *it = x;
    }

    void pop_in_place(iter it) {
        for (auto i = it; i != iter(data + head) - 1; i--) {
            *(i + 1) = *i;
        }
        head++;
    }


private:
    int cap{};
    T *data;
    int head = 0, tail = 0;
};
