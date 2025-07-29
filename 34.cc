#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex() : real(0), imag(0) {}

    // Overload >> for input in a+ib format
    friend istream& operator>>(istream& in, Complex& c) {
        char op, i_char;
        // Example accepted inputs: 3.2+4.1i, -2.5-7.6i
        in >> c.real >> op >> c.imag >> i_char;
        // 'op' is '+' or '-', 'i_char' should be 'i'
        if (op == '-') c.imag = -c.imag;
        return in;
    }

    // Overload << for output in a+ib format
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c;
    cout << "Enter complex number in a+ib format (e.g., 3.2+4.1i): ";
    cin >> c;
    cout << "Complex number: " << c << endl;
    return 0;
}