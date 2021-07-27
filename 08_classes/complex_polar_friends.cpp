// OTUS C++ basic course example of Complex class with polar coordinates

#include <cmath>
#include <cfloat>
#include <iostream>
#include <cassert>

class complex {
  private: // accesible only from class methods or friend functions and classes
    double r_;
    double phi_;

  public: // accesible from anywhere
    // Constructors
    complex() {
        r_ = 0.0;
        phi_ = 0.0;
    }

    complex(const double real) {
        r_ = real;
        phi_ = 0.0;
    }

    complex(const double real, const double imag) {
        r_ = std::sqrt(real * real + imag * imag);
        phi_ = std::atan2(imag, real);
    }

    double real() const { return r_ * std::cos(phi_); }
    
    double imag() const { return r_ * std::sin(phi_); }

    double abs() const {
        return r_;
    }

    double angle() const {
        return phi_;
    }

    friend complex add(const complex &lhs, const complex &rhs) {
        return complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
    }

    friend complex sub(const complex &lhs, const complex &rhs) {
        return complex(lhs.real() - rhs.real(), lhs.imag() - rhs.imag());
    }

    friend complex mul(const complex &lhs, const complex &rhs) {
        complex res;
        res.r_ = lhs.r_ * rhs.r_;
        res.phi_ = lhs.phi_ + rhs.phi_;
        return res;
    }

    friend complex div(const complex &lhs, const complex &rhs) {
        assert(std::abs(rhs.r_) > DBL_EPSILON);
        complex res;
        res.r_ = lhs.r_ / rhs.r_;
        res.phi_ = lhs.phi_ - rhs.phi_;
        return res;
    }
};

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