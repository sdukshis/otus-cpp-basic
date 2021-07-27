#include <iostream>

#include "complex.hpp"

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
