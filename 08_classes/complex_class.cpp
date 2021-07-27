// OTUS C++ basic course example of Complex class with cartesian coordinates

#include <cmath>
#include <cfloat>
#include <iostream>
#include <cassert>

class complex {
  private: // accesible only from class methods or friend functions and classes
    double real_;
    double imag_;

  public: // accesible from anywhere
    // Constructor
    complex(const double real, const double imag) {
        real_ = real;
        imag_ = imag;
    }

    double real() const { return real_; }
    
    double imag() const { return imag_; }

    double abs() const {
        return std::sqrt(real_ * real_ + imag_ * imag_);
    }

    double angle() const {
        return std::atan2(imag_, real_);
    }
};

complex add(const complex &lhs, const complex &rhs) {
    return complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}

complex sub(const complex &lhs, const complex &rhs) {
    return complex(lhs.real() - rhs.real(), lhs.imag() - rhs.imag());
}

complex mul(const complex &lhs, const complex &rhs) {
    return complex(lhs.real() * rhs.real() - lhs.imag() * rhs.imag(),
                   lhs.real() * rhs.imag() + lhs.imag() * rhs.real());
}

complex div(const complex &lhs, const complex &rhs) {
    const double rhs2 = rhs.real() * rhs.real() + rhs.imag() * rhs.imag();
    assert(std::abs(rhs2) > DBL_EPSILON);
    return complex((lhs.real() * rhs.real() + lhs.imag() * rhs.imag()) / rhs2,
                   (lhs.imag() * rhs.real() - lhs.real() * rhs.imag()) / rhs2);
}

void print(std::ostream &out, const complex &z) {
    out << '(' << z.real() << ',' << z.imag() << ')';
}

int main() {
    using std::cout;
    complex z(1.0, 1.0);
    cout << "abs(z) = " << z.abs() << '\n';
    cout << "angle(z) = " << z.angle() << '\n';
    cout << "z + z = "; print(cout, add(z, z)); cout << '\n';
    cout << "z - z = "; print(cout, sub(z, z)); cout << '\n';
    cout << "z * z = "; print(cout, mul(z, z)); cout << '\n';
    cout << "z / z = "; print(cout, div(z, z)); cout << '\n';
}