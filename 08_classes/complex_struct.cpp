// OTUS C++ basic course example of complex struct with cartesian coordinates

#include <cmath>
#include <cfloat>
#include <iostream>
#include <cassert>

struct complex {
    double real;
    double imag;
};

double abs(const complex &z) {
    return std::sqrt(z.real * z.real + z.imag * z.imag);
}

double angle(const complex &z) { return std::atan2(z.imag, z.real); }

complex add(const complex &lhs, const complex &rhs) {
    complex res;
    res.real = lhs.real + rhs.real;
    res.imag = lhs.imag + rhs.imag;
    return res;
}

complex sub(const complex &lhs, const complex &rhs) {
    complex res;
    res.real = lhs.real - rhs.real;
    res.imag = lhs.imag - rhs.imag;
    return res;
}

complex mul(const complex &lhs, const complex &rhs) {
    complex res;
    res.real = lhs.real * rhs.real - lhs.imag * rhs.imag;
    res.imag = lhs.real * rhs.imag + lhs.imag * rhs.real;
    return res;
}

complex div(const complex &lhs, const complex &rhs) {
    const double rhs2 = rhs.real * rhs.real + rhs.imag * rhs.imag;
    assert(std::abs(rhs2) > DBL_EPSILON);
    complex res;
    res.real = (lhs.real * rhs.real + lhs.imag * rhs.imag) / rhs2;
    res.imag = (lhs.imag * rhs.real - lhs.real * rhs.imag) / rhs2;
    return res;
}

void print(std::ostream &out, const complex &z) {
    out << '(' << z.real << ',' << z.imag << ')';
}

int main() {
    using std::cout;
    complex z;
    z.real = 1.0; z.imag = 1.0;
    cout << "abs(z) = " << abs(z) << '\n';
    cout << "angle(z) = " << angle(z) << '\n';
    cout << "z + z = "; print(cout, add(z, z)); cout << '\n';
    cout << "z - z = "; print(cout, sub(z, z)); cout << '\n';
    cout << "z * z = "; print(cout, mul(z, z)); cout << '\n';
    cout << "z / z = "; print(cout, div(z, z)); cout << '\n';
}
