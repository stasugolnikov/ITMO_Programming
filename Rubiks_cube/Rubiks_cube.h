#pragma once

class Face {
public:
    int a, b, c, d, e, f, g, h, k;

    Face() = default;

    Face(int x) : a(x), b(x), c(x), d(x), e(x), f(x), g(x), h(x), k(x) {};

};


class Cube {
private:
    Face f, b, r, l, u, d;

    void FrontRotate();

    void FrontCounterRotate();

    void BackRotate();

    void BackCounterRotate();

    void RightRotate();

    void RightCounterRotate();

    void LeftRotate();

    void LeftCounterRotate();

    void UpRotate();

    void UpCounterRotate();

    void DownRotate();

    void DownCounterRotate();

    bool OneCornerCheck() const;

    bool CornerCheck() const;

    bool CubeAssembled() const;

public:
    void read();

    void write() const;

    bool check() const;

    void show() const;

    void rotation(char face, unsigned short mode);

    void generate_condition();

    void solve_cube();

};
