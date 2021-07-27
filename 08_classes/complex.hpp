// OTUS C++ basic course example of Complex class with polar coordinates
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cassert>
#include <cfloat>
#include <cmath>
#include <ostream>

class complex {
  public: // accesible from anywhere
    // Constructors
    complex();

    complex(const double real);

    complex(const double real, const double imag);

    double real() const;

    double imag() const;

    double abs() const;

    double angle() const;

    friend complex add(const complex &lhs, const complex &rhs);

    friend complex sub(const complex &lhs, const complex &rhs);

    friend complex mul(const complex &lhs, const complex &rhs);

    friend complex div(const complex &lhs, const complex &rhs);

  private: // accesible only from class methods or friend functions and classes
    double r_;
    double phi_;
};

inline complex::complex() {
    r_ = 0.0;
    phi_ = 0.0;
}

inline complex::complex(const double real) {
    r_ = real;
    phi_ = 0.0;
}

inline complex::complex(const double real, const double imag) {
    r_ = std::sqrt(real * real + imag * imag);
    phi_ = std::atan2(imag, real);
}

inline double complex::real() const { return r_ * std::cos(phi_); }

inline double complex::imag() const { return r_ * std::sin(phi_); }

inline double complex::abs() const { return r_; }

inline double complex::angle() const { return phi_; }

inline complex add(const complex &lhs, const complex &rhs) {
    return complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}

inline complex sub(const complex &lhs, const complex &rhs) {
    return complex(lhs.real() - rhs.real(), lhs.imag() - rhs.imag());
}

inline complex mul(const complex &lhs, const complex &rhs) {
    complex res;
    res.r_ = lhs.r_ * rhs.r_;
    res.phi_ = lhs.phi_ + rhs.phi_;
    return res;
}

inline complex div(const complex &lhs, const complex &rhs) {
    assert(std::abs(rhs.r_) > DBL_EPSILON);
    complex res;
    res.r_ = lhs.r_ / rhs.r_;
    res.phi_ = lhs.phi_ - rhs.phi_;
    return res;
}

inline void print(std::ostream &out, const complex &z) {
    out << '(' << z.real() << ',' << z.imag() << ')';
}
#endif // COMPLEX_HPP
