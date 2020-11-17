//
// Created by Stanislav Ugolnikov on 12.06.2020.
//

#include "Rubiks_cube.h"
#include <fstream>
#include <iostream>
#include <vector>


void Cube::read() {
    std::ifstream fin("Cube.in");

    fin >> r.a >> r.b >> r.c >> r.d >> r.e >> r.f >> r.g >> r.h >> r.k;

    fin >> l.a >> l.b >> l.c >> l.d >> l.e >> l.f >> l.g >> l.h >> l.k;

    fin >> f.a >> f.b >> f.c >> f.d >> f.e >> f.f >> f.g >> f.h >> f.k;

    fin >> b.a >> b.b >> b.c >> b.d >> b.e >> b.f >> b.g >> b.h >> b.k;

    fin >> u.a >> u.b >> u.c >> u.d >> u.e >> u.f >> u.g >> u.h >> u.k;

    fin >> d.a >> d.b >> d.c >> d.d >> d.e >> d.f >> d.g >> d.h >> d.k;

    fin.close();
}

void Cube::write() const {
    std::ofstream fout("Cube.out");

    fout << "       " << u.a << " " << u.b << " " << u.c << "\n";
    fout << "       " << u.d << " " << u.e << " " << u.f << "\n";
    fout << "       " << u.g << " " << u.h << " " << u.k << "\n" << "\n";

    fout << l.a << " " << l.b << " " << l.c << "  " << f.a << " " << f.b << " " << f.c << "  ";
    fout << r.a << " " << r.b << " " << r.c << "  " << b.a << " " << b.b << " " << b.c << "\n";
    fout << l.d << " " << l.e << " " << l.f << "  " << f.d << " " << f.e << " " << f.f << "  ";
    fout << r.d << " " << r.e << " " << r.f << "  " << b.d << " " << b.e << " " << b.f << "\n";
    fout << l.g << " " << l.h << " " << l.k << "  " << f.g << " " << f.h << " " << f.k << "  ";
    fout << r.g << " " << r.h << " " << r.k << "  " << b.g << " " << b.h << " " << b.k << "\n" << "\n";

    fout << "       " << d.a << " " << d.b << " " << d.c << "\n";
    fout << "       " << d.d << " " << d.e << " " << d.f << "\n";
    fout << "       " << d.g << " " << d.h << " " << d.k << "\n";

    fout.close();
}

void Cube::show() const {
    std::cout << "       " << u.a << " " << u.b << " " << u.c << "\n";
    std::cout << "       " << u.d << " " << u.e << " " << u.f << "\n";
    std::cout << "       " << u.g << " " << u.h << " " << u.k << "\n" << "\n";

    std::cout << l.a << " " << l.b << " " << l.c << "  " << f.a << " " << f.b << " " << f.c << "  ";
    std::cout << r.a << " " << r.b << " " << r.c << "  " << b.a << " " << b.b << " " << b.c << "\n";
    std::cout << l.d << " " << l.e << " " << l.f << "  " << f.d << " " << f.e << " " << f.f << "  ";
    std::cout << r.d << " " << r.e << " " << r.f << "  " << b.d << " " << b.e << " " << b.f << "\n";
    std::cout << l.g << " " << l.h << " " << l.k << "  " << f.g << " " << f.h << " " << f.k << "  ";
    std::cout << r.g << " " << r.h << " " << r.k << "  " << b.g << " " << b.h << " " << b.k << "\n" << "\n";

    std::cout << "       " << d.a << " " << d.b << " " << d.c << "\n";
    std::cout << "       " << d.d << " " << d.e << " " << d.f << "\n";
    std::cout << "       " << d.g << " " << d.h << " " << d.k << "\n";
    std::cout << "\n";

}

void Cube::FrontRotate() {
    int a_tmp = f.a;
    int b_tmp = f.b;
    int c_tmp = f.c;
    int d_tmp = f.d;
    int e_tmp = f.e;
    int f_tmp = f.f;
    int g_tmp = f.g;
    int h_tmp = f.h;
    int k_tmp = f.k;

    f.a = g_tmp;
    f.b = d_tmp;
    f.c = a_tmp;
    f.d = h_tmp;
    f.e = e_tmp;
    f.f = b_tmp;
    f.g = k_tmp;
    f.h = f_tmp;
    f.k = c_tmp;

    int tmp1 = r.g;
    r.g = u.k;
    int tmp2 = d.a;
    d.a = tmp1;
    tmp1 = l.c;
    l.c = tmp2;
    u.k = tmp1;

    tmp1 = r.d;
    r.d = u.h;
    tmp2 = d.b;
    d.b = tmp1;
    tmp1 = l.f;
    l.f = tmp2;
    u.h = tmp1;

    tmp1 = r.a;
    r.a = u.g;
    tmp2 = d.c;
    d.c = tmp1;
    tmp1 = l.k;
    l.k = tmp2;
    u.g = tmp1;

}

void Cube::FrontCounterRotate() {
    int a_tmp = f.a;
    int b_tmp = f.b;
    int c_tmp = f.c;
    int d_tmp = f.d;
    int e_tmp = f.e;
    int f_tmp = f.f;
    int g_tmp = f.g;
    int h_tmp = f.h;
    int k_tmp = f.k;

    f.a = c_tmp;
    f.b = f_tmp;
    f.c = k_tmp;
    f.d = b_tmp;
    f.e = e_tmp;
    f.f = h_tmp;
    f.g = a_tmp;
    f.h = d_tmp;
    f.k = g_tmp;

    int tmp1 = u.k;
    u.k = r.g;
    int tmp2 = l.c;
    l.c = tmp1;
    tmp1 = d.a;
    d.a = tmp2;
    r.g = tmp1;

    tmp1 = u.h;
    u.h = r.d;
    tmp2 = l.f;
    l.f = tmp1;
    tmp1 = d.b;
    d.b = tmp2;
    r.d = tmp1;

    tmp1 = u.g;
    u.g = r.a;
    tmp2 = l.k;
    l.k = tmp1;
    tmp1 = d.c;
    d.c = tmp2;
    r.a = tmp1;
}

void Cube::BackRotate() {
    int a_tmp = b.a;
    int b_tmp = b.b;
    int c_tmp = b.c;
    int d_tmp = b.d;
    int e_tmp = b.e;
    int f_tmp = b.f;
    int g_tmp = b.g;
    int h_tmp = b.h;
    int k_tmp = b.k;

    b.a = g_tmp;
    b.b = d_tmp;
    b.c = a_tmp;
    b.d = h_tmp;
    b.e = e_tmp;
    b.f = b_tmp;
    b.g = k_tmp;
    b.h = f_tmp;
    b.k = c_tmp;

    int tmp1 = l.a;
    l.a = u.c;
    int tmp2 = d.g;
    d.g = tmp1;
    tmp1 = r.k;
    r.k = tmp2;
    u.c = tmp1;

    tmp1 = l.d;
    l.d = u.b;
    tmp2 = d.h;
    d.h = tmp1;
    tmp1 = r.f;
    r.f = tmp2;
    u.b = tmp1;

    tmp1 = l.g;
    l.g = u.a;
    tmp2 = d.k;
    d.k = tmp1;
    tmp1 = r.c;
    r.c = tmp2;
    u.a = tmp1;
}

void Cube::BackCounterRotate() {
    int a_tmp = b.a;
    int b_tmp = b.b;
    int c_tmp = b.c;
    int d_tmp = b.d;
    int e_tmp = b.e;
    int f_tmp = b.f;
    int g_tmp = b.g;
    int h_tmp = b.h;
    int k_tmp = b.k;

    b.a = c_tmp;
    b.b = f_tmp;
    b.c = k_tmp;
    b.d = b_tmp;
    b.e = e_tmp;
    b.f = h_tmp;
    b.g = a_tmp;
    b.h = d_tmp;
    b.k = g_tmp;

    int tmp1 = r.k;
    r.k = u.c;
    int tmp2 = d.g;
    d.g = tmp1;
    tmp1 = l.a;
    l.a = tmp2;
    u.c = tmp1;

    tmp1 = r.f;
    r.f = u.b;
    tmp2 = d.h;
    d.h = tmp1;
    tmp1 = l.d;
    l.d = tmp2;
    u.b = tmp1;

    tmp1 = r.c;
    r.c = u.a;
    tmp2 = d.k;
    d.k = tmp1;
    tmp1 = l.g;
    l.g = tmp2;
    u.a = tmp1;
}

void Cube::RightRotate() {
    int a_tmp = r.a;
    int b_tmp = r.b;
    int c_tmp = r.c;
    int d_tmp = r.d;
    int e_tmp = r.e;
    int f_tmp = r.f;
    int g_tmp = r.g;
    int h_tmp = r.h;
    int k_tmp = r.k;

    r.a = g_tmp;
    r.b = d_tmp;
    r.c = a_tmp;
    r.d = h_tmp;
    r.e = e_tmp;
    r.f = b_tmp;
    r.g = k_tmp;
    r.h = f_tmp;
    r.k = c_tmp;

    int tmp1 = u.c;
    u.c = f.c;
    int tmp2 = b.c;
    b.c = tmp1;
    tmp1 = d.c;
    d.c = tmp2;
    f.c = tmp1;

    tmp1 = u.f;
    u.f = f.f;
    tmp2 = b.f;
    b.f = tmp1;
    tmp1 = d.f;
    d.f = tmp2;
    f.f = tmp1;

    tmp1 = u.k;
    u.k = f.k;
    tmp2 = b.k;
    b.k = tmp1;
    tmp1 = d.k;
    d.k = tmp2;
    f.k = tmp1;
}

void Cube::RightCounterRotate() {
    int a_tmp = r.a;
    int b_tmp = r.b;
    int c_tmp = r.c;
    int d_tmp = r.d;
    int e_tmp = r.e;
    int f_tmp = r.f;
    int g_tmp = r.g;
    int h_tmp = r.h;
    int k_tmp = r.k;

    r.a = c_tmp;
    r.b = f_tmp;
    r.c = k_tmp;
    r.d = b_tmp;
    r.e = e_tmp;
    r.f = h_tmp;
    r.g = a_tmp;
    r.h = d_tmp;
    r.k = g_tmp;

    int tmp1 = u.c;
    u.c = b.c;
    int tmp2 = f.c;
    f.c = tmp1;
    tmp1 = d.c;
    d.c = tmp2;
    b.c = tmp1;

    tmp1 = u.f;
    u.f = b.f;
    tmp2 = f.f;
    f.f = tmp1;
    tmp1 = d.f;
    d.f = tmp2;
    b.f = tmp1;

    tmp1 = u.k;
    u.k = b.k;
    tmp2 = f.k;
    f.k = tmp1;
    tmp1 = d.k;
    d.k = tmp2;
    b.k = tmp1;
}

void Cube::LeftRotate() {
    int a_tmp = l.a;
    int b_tmp = l.b;
    int c_tmp = l.c;
    int d_tmp = l.d;
    int e_tmp = l.e;
    int f_tmp = l.f;
    int g_tmp = l.g;
    int h_tmp = l.h;
    int k_tmp = l.k;

    l.a = g_tmp;
    l.b = d_tmp;
    l.c = a_tmp;
    l.d = h_tmp;
    l.e = e_tmp;
    l.f = b_tmp;
    l.g = k_tmp;
    l.h = f_tmp;
    l.k = c_tmp;

    int tmp1 = u.a;
    u.a = b.a;
    int tmp2 = f.a;
    f.a = tmp1;
    tmp1 = d.a;
    d.a = tmp2;
    b.a = tmp1;

    tmp1 = u.d;
    u.d = b.d;
    tmp2 = f.d;
    f.d = tmp1;
    tmp1 = d.d;
    d.d = tmp2;
    b.d = tmp1;

    tmp1 = u.g;
    u.g = b.g;
    tmp2 = f.g;
    f.g = tmp1;
    tmp1 = d.g;
    d.g = tmp2;
    b.g = tmp1;


}

void Cube::LeftCounterRotate() {
    int a_tmp = l.a;
    int b_tmp = l.b;
    int c_tmp = l.c;
    int d_tmp = l.d;
    int e_tmp = l.e;
    int f_tmp = l.f;
    int g_tmp = l.g;
    int h_tmp = l.h;
    int k_tmp = l.k;

    l.a = c_tmp;
    l.b = f_tmp;
    l.c = k_tmp;
    l.d = b_tmp;
    l.e = e_tmp;
    l.f = h_tmp;
    l.g = a_tmp;
    l.h = d_tmp;
    l.k = g_tmp;

    int tmp1 = u.a;
    u.a = f.a;
    int tmp2 = b.a;
    b.a = tmp1;
    tmp1 = d.a;
    d.a = tmp2;
    f.a = tmp1;

    tmp1 = u.d;
    u.d = f.d;
    tmp2 = b.d;
    b.d = tmp1;
    tmp1 = d.d;
    d.d = tmp2;
    f.d = tmp1;

    tmp1 = u.g;
    u.g = f.g;
    tmp2 = b.g;
    b.g = tmp1;
    tmp1 = d.g;
    d.g = tmp2;
    f.g = tmp1;
}


void Cube::UpRotate() {
    int a_tmp = u.a;
    int b_tmp = u.b;
    int c_tmp = u.c;
    int d_tmp = u.d;
    int e_tmp = u.e;
    int f_tmp = u.f;
    int g_tmp = u.g;
    int h_tmp = u.h;
    int k_tmp = u.k;

    u.a = g_tmp;
    u.b = d_tmp;
    u.c = a_tmp;
    u.d = h_tmp;
    u.e = e_tmp;
    u.f = b_tmp;
    u.g = k_tmp;
    u.h = f_tmp;
    u.k = c_tmp;

    int tmp1 = f.a;
    f.a = r.a;
    int tmp2 = l.a;
    l.a = tmp1;
    tmp1 = b.k;
    b.k = tmp2;
    r.a = tmp1;

    tmp1 = f.b;
    f.b = r.b;
    tmp2 = l.b;
    l.b = tmp1;
    tmp1 = b.h;
    b.h = tmp2;
    r.b = tmp1;

    tmp1 = f.c;
    f.c = r.c;
    tmp2 = l.c;
    l.c = tmp1;
    tmp1 = b.g;
    b.g = tmp2;
    r.c = tmp1;
}

void Cube::UpCounterRotate() {
    int a_tmp = u.a;
    int b_tmp = u.b;
    int c_tmp = u.c;
    int d_tmp = u.d;
    int e_tmp = u.e;
    int f_tmp = u.f;
    int g_tmp = u.g;
    int h_tmp = u.h;
    int k_tmp = u.k;

    u.a = c_tmp;
    u.b = f_tmp;
    u.c = k_tmp;
    u.d = b_tmp;
    u.e = e_tmp;
    u.f = h_tmp;
    u.g = a_tmp;
    u.h = d_tmp;
    u.k = g_tmp;

    int tmp1 = r.a;
    r.a = f.a;
    int tmp2 = b.k;
    b.k = tmp1;
    tmp1 = l.a;
    l.a = tmp2;
    f.a = tmp1;

    tmp1 = r.b;
    r.b = f.b;
    tmp2 = b.h;
    b.h = tmp1;
    tmp1 = l.b;
    l.b = tmp2;
    f.b = tmp1;

    tmp1 = r.c;
    r.c = f.c;
    tmp2 = b.g;
    b.g = tmp1;
    tmp1 = l.c;
    l.c = tmp2;
    f.c = tmp1;
}

void Cube::DownRotate() {
    int a_tmp = d.a;
    int b_tmp = d.b;
    int c_tmp = d.c;
    int d_tmp = d.d;
    int e_tmp = d.e;
    int f_tmp = d.f;
    int g_tmp = d.g;
    int h_tmp = d.h;
    int k_tmp = d.k;

    d.a = c_tmp;
    d.b = f_tmp;
    d.c = k_tmp;
    d.d = b_tmp;
    d.e = e_tmp;
    d.f = h_tmp;
    d.g = a_tmp;
    d.h = d_tmp;
    d.k = g_tmp;

    int tmp1 = f.g;
    f.g = r.g;
    int tmp2 = l.g;
    l.g = tmp1;
    tmp1 = b.c;
    b.c = tmp2;
    r.g = tmp1;

    tmp1 = f.h;
    f.h = r.h;
    tmp2 = l.h;
    l.h = tmp1;
    tmp1 = b.b;
    b.b = tmp2;
    r.h = tmp1;

    tmp1 = f.k;
    f.k = r.k;
    tmp2 = l.k;
    l.k = tmp1;
    tmp1 = b.a;
    b.a = tmp2;
    r.k = tmp1;
}

void Cube::DownCounterRotate() {
    int a_tmp = d.a;
    int b_tmp = d.b;
    int c_tmp = d.c;
    int d_tmp = d.d;
    int e_tmp = d.e;
    int f_tmp = d.f;
    int g_tmp = d.g;
    int h_tmp = d.h;
    int k_tmp = d.k;

    d.a = c_tmp;
    d.b = f_tmp;
    d.c = k_tmp;
    d.d = b_tmp;
    d.e = e_tmp;
    d.f = h_tmp;
    d.g = a_tmp;
    d.h = d_tmp;
    d.k = g_tmp;

    int tmp1 = r.g;
    r.g = f.g;
    int tmp2 = b.c;
    b.c = tmp1;
    tmp1 = l.g;
    l.g = tmp2;
    f.g = tmp1;

    tmp1 = r.h;
    r.h = f.h;
    tmp2 = b.b;
    b.b = tmp1;
    tmp1 = l.h;
    l.h = tmp2;
    f.h = tmp1;

    tmp1 = r.k;
    r.k = f.k;
    tmp2 = b.a;
    b.a = tmp1;
    tmp1 = l.k;
    l.k = tmp2;
    f.k = tmp1;
}

void Cube::generate_condition() {
    int num_comm = abs(rand() % 10);
    for (int i = 0; i < num_comm; ++i) {
        int x = abs(rand() % 12);
        if (x == 0) RightRotate();
        if (x == 1) RightCounterRotate();
        if (x == 2) LeftRotate();
        if (x == 3) LeftCounterRotate();
        if (x == 4) FrontRotate();
        if (x == 5) FrontCounterRotate();
        if (x == 6) BackRotate();
        if (x == 7) BackCounterRotate();
        if (x == 8) UpRotate();
        if (x == 9) UpCounterRotate();
        if (x == 10) DownRotate();
        if (x == 11) DownCounterRotate();
    }
    std::cout << "\n";
}

void Cube::rotation(char face, unsigned short mode) {
    if (face == 'r' && mode == 0) {
        RightRotate();
    }
    if (face == 'r' && mode == 1) {
        RightCounterRotate();
    }
    if (face == 'l' && mode == 0) {
        LeftRotate();
    }
    if (face == 'l' && mode == 1) {
        LeftCounterRotate();
    }
    if (face == 'f' && mode == 0) {
        FrontRotate();
    }
    if (face == 'f' && mode == 1) {
        FrontCounterRotate();
    }
    if (face == 'b' && mode == 0) {
        BackRotate();
    }
    if (face == 'b' && mode == 1) {
        BackCounterRotate();
    }
    if (face == 'u' && mode == 0) {
        UpRotate();
    }
    if (face == 'u' && mode == 1) {
        UpCounterRotate();
    }
    if (face == 'd' && mode == 0) {
        DownRotate();
    }
    if (face == 'd' && mode == 1) {
        DownCounterRotate();
    }
}

bool Cube::check() const {
    std::vector<int> a(6,0);
    a[f.a]++;
    a[f.b]++;
    a[f.c]++;
    a[f.d]++;
    a[f.e]++;
    a[f.f]++;
    a[f.g]++;
    a[f.h]++;
    a[f.k]++;

    a[b.a]++;
    a[b.b]++;
    a[b.c]++;
    a[b.d]++;
    a[b.e]++;
    a[b.f]++;
    a[b.g]++;
    a[b.h]++;
    a[b.k]++;

    a[r.a]++;
    a[r.b]++;
    a[r.c]++;
    a[r.d]++;
    a[r.e]++;
    a[r.f]++;
    a[r.g]++;
    a[r.h]++;
    a[r.k]++;

    a[l.a]++;
    a[l.b]++;
    a[l.c]++;
    a[l.d]++;
    a[l.e]++;
    a[l.f]++;
    a[l.g]++;
    a[l.h]++;
    a[l.k]++;

    a[u.a]++;
    a[u.b]++;
    a[u.c]++;
    a[u.d]++;
    a[u.e]++;
    a[u.f]++;
    a[u.g]++;
    a[u.h]++;
    a[u.k]++;

    a[d.a]++;
    a[d.b]++;
    a[d.c]++;
    a[d.d]++;
    a[d.e]++;
    a[d.f]++;
    a[d.g]++;
    a[d.h]++;
    a[d.k]++;

    for (int i : a) {
        if (i != 9) return false;
    }
    return true;
}


bool Cube::CornerCheck() const {
    return ((u.k == 4 && f.c == 0 && r.a == 3) || (u.k == 4 && f.c == 3 && r.a == 0) ||
            (u.k == 0 && f.c == 4 && r.a == 3) || (u.k == 0 && f.c == 3 && r.a == 4) ||
            (u.k == 3 && f.c == 0 && r.a == 4) || (u.k == 3 && f.c == 4 && r.a == 0)) &&
           ((f.a == 0 && l.c == 2 && u.g == 4) || (f.a == 0 && l.c == 4 && u.g == 2) ||
            (f.a == 2 && l.c == 4 && u.g == 0) || (f.a == 2 && l.c == 0 && u.g == 4) ||
            (f.a == 4 && l.c == 2 && u.g == 0) || (f.a == 4 && l.c == 0 && u.g == 2)) &&
           ((u.c == 4 && r.c == 3 && b.k == 1) || (u.c == 4 && r.c == 1 && b.k == 3) ||
            (u.c == 3 && r.c == 4 && b.k == 1) || (u.c == 3 && r.c == 1 && b.k == 4) ||
            (u.c == 1 && r.c == 3 && b.k == 4) || (u.c == 1 && r.c == 4 && b.k == 3)) &&
           ((u.a == 4 && b.g == 1 && l.a == 2) || (u.a == 4 && b.g == 2 && l.a == 1) ||
            (u.a == 2 && b.g == 1 && l.a == 4) || (u.a == 2 && b.g == 4 && l.a == 1) ||
            (u.a == 1 && b.g == 4 && l.a == 2) || (u.a == 1 && b.g == 2 && l.a == 4));
}

bool Cube::CubeAssembled() const {
    return f.a == 0 && f.b == 0 && f.c == 0 && f.d == 0 && f.e == 0 && f.f == 0 && f.g == 0 && f.h == 0 && f.k == 0 &&
           b.a == 1 && b.b == 1 && b.c == 1 && b.d == 1 && b.e == 1 && b.f == 1 && b.g == 1 && b.h == 1 && b.k == 1 &&
           r.a == 3 && r.b == 3 && r.c == 3 && r.d == 3 && r.e == 3 && r.f == 3 && r.g == 3 && r.h == 3 && r.k == 3 &&
           l.a == 2 && l.b == 2 && l.c == 2 && l.d == 2 && l.e == 2 && l.f == 2 && l.g == 2 && l.h == 2 && l.k == 2 &&
           u.a == 4 && u.b == 4 && u.c == 4 && u.d == 4 && u.e == 4 && u.f == 4 && u.g == 4 && u.h == 4 && u.k == 4 &&
           d.a == 5 && d.b == 5 && d.c == 5 && d.d == 5 && d.e == 5 && d.f == 5 && d.g == 5 && d.h == 5 && d.k == 5;
}

void Cube::solve_cube() {
    if (!CubeAssembled() && check()) {
        while (u.b != 5 || u.d != 5 || u.f != 5 || u.h != 5) {
            if (f.f == 5) {
                while (u.f == 5) {
                    UpRotate();
                }
                RightRotate();
            }
            if (f.d == 5) {
                while (u.d == 5) {
                    UpRotate();
                }
                LeftCounterRotate();
            }
            if (r.d == 5) {
                while (u.h == 5) {
                    UpRotate();
                }
                FrontCounterRotate();
            }
            if (r.f == 5) {
                while (u.b == 5) {
                    UpRotate();
                }
                BackRotate();
            }
            if (l.f == 5) {
                while (u.h == 5) {
                    UpRotate();
                }
                FrontRotate();
            }
            if (l.d == 5) {
                while (u.b == 5) {
                    UpRotate();
                }
                BackCounterRotate();
            }
            if (b.f == 5) {
                while (u.f == 5) {
                    UpRotate();
                }
                RightCounterRotate();
            }
            if (b.d == 5) {
                while (u.d == 5) {
                    UpRotate();
                }
                LeftRotate();
            }
            if (d.f == 5) {
                while (u.f == 5) {
                    UpRotate();
                }
                RightRotate();
                RightRotate();
            }
            if (d.h == 5) {
                while (u.b == 5) {
                    UpRotate();
                }
                BackCounterRotate();
                BackCounterRotate();
            }
            if (d.d == 5) {
                while (u.d == 5) {
                    UpRotate();
                }
                LeftCounterRotate();
                LeftCounterRotate();
            }
            if (d.b == 5) {
                while (u.h == 5) {
                    UpRotate();
                }
                FrontRotate();
                FrontRotate();
            }

            if (f.h == 5) {
                FrontRotate();
                while (u.d == 5) {
                    UpRotate();
                }
                LeftCounterRotate();
            }
            if (f.b == 5) {
                FrontRotate();
                while (u.f == 5) {
                    UpRotate();
                }
                RightRotate();
            }
            if (r.h == 5) {
                RightRotate();
                while (u.h == 5) {
                    UpRotate();
                }
                FrontCounterRotate();
            }
            if (r.b == 5) {
                RightRotate();
                while (u.b == 5) {
                    UpRotate();
                }
                BackRotate();
            }
            if (b.b == 5) {
                BackCounterRotate();
                while (u.d == 5) {
                    UpRotate();
                }
                LeftRotate();
            }
            if (b.h == 5) {
                BackCounterRotate();
                while (u.f == 5) {
                    UpRotate();
                }
                RightCounterRotate();
            }
            if (l.h == 5) {
                LeftCounterRotate();
                while (u.h == 5) {
                    UpRotate();
                }
                FrontRotate();
            }
            if (l.b == 5) {
                LeftCounterRotate();
                while (u.b == 5) {
                    UpRotate();
                }
                BackCounterRotate();
            }
        }    ///Собран цветок

        while (f.b != f.e || u.h != 5) {
            UpRotate();
        }
        FrontRotate();
        FrontRotate();
        while (r.b != r.e || u.f != 5) {
            UpRotate();
        }
        RightRotate();
        RightRotate();
        while (b.h != b.e || u.b != 5) {
            UpRotate();
        }
        BackRotate();
        BackRotate();
        while (l.b != l.e || u.d != 5) {
            UpRotate();
        }
        LeftRotate();
        LeftRotate(); /// Построен белый крест

        int count = 0;
        while (d.a != 5 || d.c != 5 || d.g != 5 || d.k != 5) {
            if (b.k == 5) {
                if ((u.c == 3 && r.c == 1) || (u.c == 1 && r.c == 3)) {
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }

                }
                if ((u.c == 3 && r.c == 0 && b.k == 5) || (u.c == 0 && r.c == 3 && b.k == 5)) {
                    UpRotate();
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.c == 0 && r.c == 2 && b.k == 5) || (u.c == 2 && r.c == 0 && b.k == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.c == 2 && r.c == 1 && b.k == 5) || (u.c == 1 && r.c == 2 && b.k == 5)) {
                    UpCounterRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if (u.c == 5) {
                if ((b.k == 3 && r.c == 1) || (b.k == 1 && r.c == 3)) {
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((b.k == 3 && r.c == 0 && u.c == 5) || (b.k == 0 && r.c == 3 && u.c == 5)) {
                    UpRotate();
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((b.k == 0 && r.c == 2 && u.c == 5) || (b.k == 2 && r.c == 0 && u.c == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((b.k == 2 && r.c == 1 && u.c == 5) || (b.k == 1 && r.c == 2 && u.c == 5)) {
                    UpCounterRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if (r.c == 5) {
                if ((u.c == 3 && b.k == 1) || (u.c == 1 && b.k == 3)) {
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.c == 3 && b.k == 0 && r.c == 5) || (u.c == 0 && b.k == 3 && r.c == 5)) {
                    UpRotate();
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.c == 0 && b.k == 2 && r.c == 5) || (u.c == 2 && b.k == 0 && r.c == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.c == 2 && b.k == 1 && r.c == 5) || (u.c == 1 && b.k == 2 && r.c == 5)) {
                    UpCounterRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }
            if (b.g == 5) {
                if ((u.a == 3 && l.a == 1) || (u.a == 1 && l.a == 3)) {
                    UpRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.a == 3 && l.a == 0 && b.g == 5) || (u.a == 0 && l.a == 3 && b.g == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.c != 5 || f.k != 3 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.a == 0 && l.a == 2 && b.g == 5) || (u.a == 2 && l.a == 0 && b.g == 5)) {
                    UpCounterRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.a == 2 && l.a == 1 && b.g == 5) || (u.a == 1 && l.a == 2 && b.g == 5)) {
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if (u.a == 5) {
                if ((b.g == 3 && l.a == 1) || (b.g == 1 && l.a == 3)) {
                    UpRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((b.g == 3 && l.a == 0 && u.a == 5) || (b.g == 0 && l.a == 3 && u.a == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((b.g == 0 && l.a == 2 && u.a == 5) || (b.g == 2 && l.a == 0 && u.a == 5)) {
                    UpCounterRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((b.g == 2 && l.a == 1 && u.a == 5) || (b.g == 1 && l.a == 2 && u.a == 5)) {
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if (l.a == 5) {
                if ((u.a == 3 && b.g == 1) || (u.a == 1 && b.g == 3)) {
                    UpRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.a == 3 && b.g == 0 && l.a == 5) || (u.a == 0 && b.g == 3 && l.a == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.a == 0 && b.g == 2 && l.a == 5) || (u.a == 2 && b.g == 0 && l.a == 5)) {
                    UpCounterRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.a == 2 && b.g == 1 && l.a == 5) || (u.a == 1 && b.g == 2 && l.a == 5)) {
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            } /// Закончен второй угол

            if (f.a == 5) {
                if ((u.g == 3 && l.c == 1) || (u.g == 1 && l.c == 3)) {
                    UpRotate();
                    UpRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.g == 3 && l.c == 0 && f.a == 5) || (u.g == 0 && l.c == 3 && f.a == 5)) {
                    UpCounterRotate();
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.g == 0 && l.c == 2 && f.a == 5) || (u.g == 2 && l.c == 0 && f.a == 5)) {
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.g == 2 && l.c == 1 && f.a == 5) || (u.g == 1 && l.c == 2 && f.a == 5)) {
                    UpRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if (u.g == 5) {
                if ((f.a == 3 && l.c == 1) || (f.a == 1 && l.c == 3)) {
                    UpRotate();
                    UpRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.a == 3 && l.c == 0 && u.g == 5) || (f.a == 0 && l.c == 3 && u.g == 5)) {
                    UpCounterRotate();
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.a == 0 && l.c == 2 && u.g == 5) || (f.a == 2 && l.c == 0 && u.g == 5)) {
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.a == 2 && l.c == 1 && u.g == 5) || (f.a == 1 && l.c == 2 && u.g == 5)) {
                    UpRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if (l.c == 5) {
                if ((u.g == 3 && f.a == 1) || (u.g == 1 && f.a == 3)) {
                    UpRotate();
                    UpRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.g == 3 && f.a == 0 && l.c == 5) || (u.g == 0 && f.a == 3 && l.c == 5)) {
                    UpCounterRotate();
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.g == 0 && f.a == 2 && l.c == 5) || (u.g == 2 && f.a == 0 && l.c == 5)) {
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.g == 2 && f.a == 1 && l.c == 5) || (u.g == 1 && f.a == 2 && l.c == 5)) {
                    UpRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            } /// Закончен случай третьего угла

            if (f.c == 5) {
                if ((u.k == 3 && r.a == 1) || (u.k == 1 && r.a == 3)) {
                    UpCounterRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.k == 3 && r.a == 0 && f.c == 5) || (u.k == 0 && r.a == 3 && f.c == 5)) {
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.k == 0 && r.a == 2 && f.c == 5) || (u.k == 2 && r.a == 0 && f.c == 5)) {
                    UpRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((u.k == 2 && r.a == 1 && f.c == 5) || (u.k == 1 && r.a == 2 && f.c == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if (u.k == 5) {
                if ((f.c == 3 && r.a == 1) || (f.c == 1 && r.a == 3)) {
                    UpCounterRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.c == 3 && r.a == 0 && u.k == 5) || (f.c == 0 && r.a == 3 && u.k == 5)) {
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.c == 0 && r.a == 2 && u.k == 5) || (f.c == 2 && r.a == 0 && u.k == 5)) {
                    UpRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.c == 2 && r.a == 1 && u.k == 5) || (f.c == 1 && r.a == 2 && u.k == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if (r.a == 5) {
                if ((f.c == 3 && u.k == 1 && r.a == 5) || (f.c == 1 && u.k == 3 && r.a == 5)) {
                    UpCounterRotate();
                    while (d.k != 5 || r.k != 3 || b.c != 1) {
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.c == 3 && u.k == 0 && r.a == 5) || (f.c == 0 && u.k == 3 && r.a == 5)) {
                    while (d.c != 5 || f.k != 0 || r.g != 3) {
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.c == 0 && u.k == 2 && r.a == 5) || (f.c == 2 && u.k == 0 && r.a == 5)) {
                    UpRotate();
                    while (d.a != 5 || l.k != 2 || f.g != 0) {
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                    }
                }
                if ((f.c == 2 && u.k == 1 && r.a == 5) || (f.c == 1 && u.k == 2 && r.a == 5)) {
                    UpRotate();
                    UpRotate();
                    while (d.g != 5 || b.a != 1 || l.g != 2) {
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                    }
                }
            }

            if ((f.k == 5 && r.g == 3 && d.c == 0) || (f.k == 5 && r.g == 0 && d.c == 3) ||
                (f.k == 3 && r.g == 5 && d.c == 0) || (f.k == 0 && r.g == 5 && d.c == 3) ||
                (f.k == 3 && r.g == 0 && d.c == 5)) {
                while (d.c != 5 || f.k != 0 || r.g != 3) {
                    RightRotate();
                    UpRotate();
                    RightCounterRotate();
                    UpCounterRotate();
                }
            }
            if ((b.c == 5 && r.k == 3 && d.k == 1) || (b.c == 5 && r.k == 1 && d.k == 3) ||
                (b.c == 3 && r.k == 5 && d.k == 1) || (b.c == 1 && r.k == 5 && d.k == 3) ||
                (b.c == 3 && r.k == 1 && d.k == 5)) {
                while (d.k != 5 || b.c != 1 || r.k != 3) {
                    BackRotate();
                    UpRotate();
                    BackCounterRotate();
                    UpCounterRotate();
                }
            }
            if ((b.a == 5 && l.g == 2 && d.g == 1) || (b.a == 5 && l.g == 1 && d.g == 2) ||
                (b.a == 2 && l.g == 5 && d.g == 1) || (b.a == 1 && l.g == 5 && d.g == 2) ||
                (b.a == 2 && l.g == 1 && d.g == 5)) {
                while (d.g != 5 || b.a != 1 || l.g != 2) {
                    LeftRotate();
                    UpRotate();
                    LeftCounterRotate();
                    UpCounterRotate();
                }
            }
            if ((l.k == 5 && f.g == 0 && d.a == 2) || (l.k == 5 && f.g == 2 && d.a == 0) ||
                (l.k == 0 && f.g == 5 && d.a == 2) || (l.k == 2 && f.g == 5 && d.a == 0) ||
                (l.k == 0 && f.g == 2 && d.a == 5)) {
                while (d.a != 5 || l.k != 2 || f.g != 0) {
                    FrontRotate();
                    UpRotate();
                    FrontCounterRotate();
                    UpCounterRotate();
                }
            }

            if ((d.c == 5 && (f.k != 0 && f.k != 3)) || (d.c == 5 && (r.g != 0 && r.g != 3))) {
                RightRotate();
                UpRotate();
                RightCounterRotate();
                UpCounterRotate();
            }
            if ((d.k == 5 && (r.k != 1 && r.k != 3)) || (d.k == 5 && (b.c != 1 && b.c != 3))) {
                BackRotate();
                UpRotate();
                BackCounterRotate();
                UpCounterRotate();
            }
            if ((d.g == 5 && (b.a != 1 && b.a != 2)) || (d.g == 5 && (l.g != 1 && l.g != 2))) {
                LeftRotate();
                UpRotate();
                LeftCounterRotate();
                UpCounterRotate();
            }
            if ((d.a == 5 && (f.g != 0 && f.g != 2)) || (d.a == 5 && (l.k != 0 && l.k != 2))) {
                FrontRotate();
                UpRotate();
                FrontCounterRotate();
                UpCounterRotate();
            }
        }   /// Белая грань построена
        int pred = -1;
        while (f.d != 0 || f.f != 0 || r.d != 3 || r.f != 3 || b.f != 1 || b.d != 1 || l.d != 2 || l.f != 2) {
            count = 0;
            pred = -1;
            while (count > pred) {
                pred = count;
                if (f.b == 0 || r.b == 0 || b.h == 0 || l.b == 0) {
                    while (f.b != 0) {
                        UpRotate();
                    }
                    if (u.h == 3) {
                        count++;
                        UpRotate();
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                        FrontRotate();
                        UpRotate();
                    } else {
                        if (u.h == 2) {
                            count++;
                            UpCounterRotate();
                            LeftCounterRotate();
                            UpCounterRotate();
                            LeftRotate();
                            UpRotate();
                            FrontRotate();
                            UpRotate();
                            FrontCounterRotate();
                            UpCounterRotate();
                        }
                    }
                }
                if (f.b == 3 || r.b == 3 || b.h == 3 || l.b == 3) {
                    while (r.b != 3) {
                        UpRotate();
                    }
                    if (u.f == 1) {
                        count++;
                        UpRotate();
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                        RightRotate();
                        UpRotate();
                    } else {
                        if (u.f == 0) {
                            count++;
                            UpCounterRotate();
                            FrontCounterRotate();
                            UpCounterRotate();
                            FrontRotate();
                            UpRotate();
                            RightRotate();
                            UpRotate();
                            RightCounterRotate();
                            UpCounterRotate();
                        }
                    }
                }
                if (f.b == 1 || r.b == 1 || b.h == 1 || l.b == 1) {
                    while (b.h != 1) {
                        UpRotate();
                    }
                    if (u.b == 2) {
                        count++;
                        UpRotate();
                        LeftRotate();
                        UpRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                        BackRotate();
                        UpRotate();
                    } else {
                        if (u.b == 3) {
                            count++;
                            UpCounterRotate();
                            RightCounterRotate();
                            UpCounterRotate();
                            RightRotate();
                            UpRotate();
                            BackRotate();
                            UpRotate();
                            BackCounterRotate();
                            UpCounterRotate();
                        }
                    }
                }
                if (f.b == 2 || r.b == 2 || b.h == 2 || l.b == 2) {
                    while (l.b != 2) {
                        UpRotate();
                    }
                    if (u.d == 0) {
                        count++;
                        UpRotate();
                        FrontRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                        LeftCounterRotate();
                        UpCounterRotate();
                        LeftRotate();
                        UpRotate();
                    } else {
                        if (u.d == 1) {
                            count++;
                            UpCounterRotate();
                            BackCounterRotate();
                            UpCounterRotate();
                            BackRotate();
                            UpRotate();
                            LeftRotate();
                            UpRotate();
                            LeftCounterRotate();
                            UpCounterRotate();
                        }
                    }
                }
            }
            if (f.f != 0) {
                RightRotate();
                UpRotate();
                RightCounterRotate();
                UpCounterRotate();
                FrontCounterRotate();
                UpCounterRotate();
                FrontRotate();
                UpRotate();
            }
            if (r.f != 3) {
                BackRotate();
                UpRotate();
                BackCounterRotate();
                UpCounterRotate();
                RightCounterRotate();
                UpCounterRotate();
                RightRotate();
                UpRotate();
            }
            if (b.d != 1) {
                LeftRotate();
                UpRotate();
                LeftCounterRotate();
                UpCounterRotate();
                BackCounterRotate();
                UpCounterRotate();
                BackRotate();
                UpRotate();
            }
            if (l.f != 2) {
                FrontRotate();
                UpRotate();
                FrontCounterRotate();
                UpCounterRotate();
                LeftCounterRotate();
                UpCounterRotate();
                LeftRotate();
                UpRotate();
            }
        } ///Собраны нижний и верхний уровни

        while (u.d != 4 || u.b != 4 || u.f != 4 || u.h != 4) {
            if ((u.f == 4 && u.b == 4) || (u.b == 4 && u.h == 4)) {
                LeftRotate();
                FrontRotate();
                UpRotate();
                FrontCounterRotate();
                UpCounterRotate();
                LeftCounterRotate();
            } else {
                if (u.f == 4 && u.h == 4) {
                    BackRotate();
                    LeftRotate();
                    UpRotate();
                    LeftCounterRotate();
                    UpCounterRotate();
                    BackCounterRotate();
                } else {
                    if (u.d == 4 && u.h == 4) {
                        RightRotate();
                        BackRotate();
                        UpRotate();
                        BackCounterRotate();
                        UpCounterRotate();
                        RightCounterRotate();
                    } else {
                        FrontRotate();
                        RightRotate();
                        UpRotate();
                        RightCounterRotate();
                        UpCounterRotate();
                        FrontCounterRotate();
                    }
                }
            }
        } ///Желтый крест собран
        int proverka = 0;
        if (f.b == 0 && r.b == 3 && b.h == 1 && l.b == 2) {
            proverka = 1;
        } else {
            UpRotate();
            if (f.b == 0 && r.b == 3 && b.h == 1 && l.b == 2) {
                proverka = 1;
            } else {
                UpRotate();
                if (f.b == 0 && r.b == 3 && b.h == 1 && l.b == 2) {
                    proverka = 1;
                } else {
                    UpRotate();
                    if (f.b == 0 && r.b == 3 && b.h == 1 && l.b == 2) {
                        proverka = 1;
                    }
                }
            }
        }
        if (proverka == 0) {
            while (f.b != 0 || r.b != 3 || b.h != 1 || l.b != 2) {
                UpRotate();
                if (r.b == 3 && b.h == 1) {
                    RightRotate();
                    UpRotate();
                    RightCounterRotate();
                    UpRotate();
                    RightRotate();
                    UpRotate();
                    UpRotate();
                    RightCounterRotate();
                    UpRotate();
                    break;
                }
                if (r.b == 3 && f.b == 0) {
                    FrontRotate();
                    UpRotate();
                    FrontCounterRotate();
                    UpRotate();
                    FrontRotate();
                    UpRotate();
                    UpRotate();
                    FrontCounterRotate();
                    UpRotate();
                    break;
                }
                if (f.b == 0 && l.b == 2) {
                    LeftRotate();
                    UpRotate();
                    LeftCounterRotate();
                    UpRotate();
                    LeftRotate();
                    UpRotate();
                    UpRotate();
                    LeftCounterRotate();
                    UpRotate();
                    break;
                }
                if (l.b == 2 && b.h == 1) {
                    BackRotate();
                    UpRotate();
                    BackCounterRotate();
                    UpRotate();
                    BackRotate();
                    UpRotate();
                    UpRotate();
                    BackCounterRotate();
                    UpRotate();
                    break;
                }
                if (r.b == 3 && l.b == 2) {
                    BackRotate();
                    UpRotate();
                    BackCounterRotate();
                    UpRotate();
                    BackRotate();
                    UpRotate();
                    UpRotate();
                    BackCounterRotate();
                }
                if (f.b == 0 && b.h == 1) {
                    RightRotate();
                    UpRotate();
                    RightCounterRotate();
                    UpRotate();
                    RightRotate();
                    UpRotate();
                    UpRotate();
                    RightCounterRotate();
                }
            }
        }  ///Поставили углы на свои места

        int check = 0;
        int stop = 0;
        while (!CornerCheck()) {
            if ((u.k == 4 && f.c == 0 && r.a == 3) || (u.k == 4 && f.c == 3 && r.a == 0) ||
                (u.k == 0 && f.c == 4 && r.a == 3) || (u.k == 0 && f.c == 3 && r.a == 4) ||
                (u.k == 3 && f.c == 0 && r.a == 4) || (u.k == 3 && f.c == 4 && r.a == 0)) {
                while (!CornerCheck()) {
                    UpRotate();
                    RightRotate();
                    UpCounterRotate();
                    LeftCounterRotate();
                    UpRotate();
                    RightCounterRotate();
                    UpCounterRotate();
                    LeftRotate();
                }
            } else {
                if ((f.a == 0 && l.c == 2 && u.g == 4) || (f.a == 0 && l.c == 4 && u.g == 2) ||
                    (f.a == 2 && l.c == 4 && u.g == 0) || (f.a == 2 && l.c == 0 && u.g == 4) ||
                    (f.a == 4 && l.c == 2 && u.g == 0) || (f.a == 4 && l.c == 0 && u.g == 2)) {
                    while (!CornerCheck()) {
                        UpRotate();
                        FrontRotate();
                        UpCounterRotate();
                        BackCounterRotate();
                        UpRotate();
                        FrontCounterRotate();
                        UpCounterRotate();
                        BackRotate();
                    }
                } else {
                    if ((u.c == 4 && r.c == 3 && b.k == 1) || (u.c == 4 && r.c == 1 && b.k == 3) ||
                        (u.c == 3 && r.c == 4 && b.k == 1) || (u.c == 3 && r.c == 1 && b.k == 4) ||
                        (u.c == 1 && r.c == 3 && b.k == 4) || (u.c == 1 && r.c == 4 && b.k == 3)) {
                        while (!CornerCheck()) {
                            UpRotate();
                            BackRotate();
                            UpCounterRotate();
                            FrontCounterRotate();
                            UpRotate();
                            BackCounterRotate();
                            UpCounterRotate();
                            FrontRotate();
                        }
                    } else {
                        if ((u.a == 4 && b.g == 1 && l.a == 2) || (u.a == 4 && b.g == 2 && l.a == 1) ||
                            (u.a == 2 && b.g == 1 && l.a == 4) || (u.a == 2 && b.g == 4 && l.a == 1) ||
                            (u.a == 1 && b.g == 4 && l.a == 2) || (u.a == 1 && b.g == 2 && l.a == 4)) {
                            while (!CornerCheck()) {
                                UpRotate();
                                LeftRotate();
                                UpCounterRotate();
                                RightCounterRotate();
                                UpRotate();
                                LeftCounterRotate();
                                UpCounterRotate();
                                RightRotate();
                            }
                        } else {
                            while (!OneCornerCheck()) {
                                UpRotate();
                                RightRotate();
                                UpCounterRotate();
                                LeftCounterRotate();
                                UpRotate();
                                RightCounterRotate();
                                UpCounterRotate();
                                LeftRotate();
                            }
                        }
                    }
                }
            }
        } ///Правильно поставили углы

        if (u.c != 4) {
            while (u.c != 4) {
                BackRotate();
                RightCounterRotate();
                BackCounterRotate();
                RightRotate();
            }
        }
        UpRotate();
        if (u.c != 4) {
            while (u.c != 4) {
                BackRotate();
                RightCounterRotate();
                BackCounterRotate();
                RightRotate();
            }
        }
        UpRotate();
        if (u.c != 4) {
            while (u.c != 4) {
                BackRotate();
                RightCounterRotate();
                BackCounterRotate();
                RightRotate();
            }
        }
        UpRotate();
        if (u.c != 4) {
            while (u.c != 4) {
                BackRotate();
                RightCounterRotate();
                BackCounterRotate();
                RightRotate();
            }
        } ///Добили желтную грань
        while (!CubeAssembled()) {
            UpRotate();
        }
    }
}

bool Cube::OneCornerCheck() const {
    return ((u.k == 4 && f.c == 0 && r.a == 3) || (u.k == 4 && f.c == 3 && r.a == 0) ||
            (u.k == 0 && f.c == 4 && r.a == 3) || (u.k == 0 && f.c == 3 && r.a == 4) ||
            (u.k == 3 && f.c == 0 && r.a == 4) || (u.k == 3 && f.c == 4 && r.a == 0)) ||
           ((f.a == 0 && l.c == 2 && u.g == 4) || (f.a == 0 && l.c == 4 && u.g == 2) ||
            (f.a == 2 && l.c == 4 && u.g == 0) || (f.a == 2 && l.c == 0 && u.g == 4) ||
            (f.a == 4 && l.c == 2 && u.g == 0) || (f.a == 4 && l.c == 0 && u.g == 2)) ||
           ((u.c == 4 && r.c == 3 && b.k == 1) || (u.c == 4 && r.c == 1 && b.k == 3) ||
            (u.c == 3 && r.c == 4 && b.k == 1) || (u.c == 3 && r.c == 1 && b.k == 4) ||
            (u.c == 1 && r.c == 3 && b.k == 4) || (u.c == 1 && r.c == 4 && b.k == 3)) ||
           ((u.a == 4 && b.g == 1 && l.a == 2) || (u.a == 4 && b.g == 2 && l.a == 1) ||
            (u.a == 2 && b.g == 1 && l.a == 4) || (u.a == 2 && b.g == 4 && l.a == 1) ||
            (u.a == 1 && b.g == 4 && l.a == 2) || (u.a == 1 && b.g == 2 && l.a == 4));
}
