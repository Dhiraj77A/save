#include <iostream>
using namespace std;

// Manipulator class
class Format {
    int width, precision;
    char fillChar;
public:
    Format(int w, int p, char f) : width(w), precision(p), fillChar(f) {}
    friend ostream& operator<<(ostream& os, const Format& fmt);
};

// Overload operator<< for Format
ostream& operator<<(ostream& os, const Format& fmt) {
    os.width(fmt.width);
    os.precision(fmt.precision);
    os.fill(fmt.fillChar);
    os.setf(ios::fixed, ios::floatfield); // Fixed-point
    return os;
}

int main() {
    double value;
    int width, precision;
    char fillChar;

    // Input from user
    cout << "Enter the value (double): ";
    cin >> value;
    cout << "Enter width (int): ";
    cin >> width;
    cout << "Enter precision (int): ";
    cin >> precision;
    cout << "Enter fill character (char): ";
    cin >> fillChar;
    cout <<Format(width, precision, fillChar)<< value << endl;

    return 0;
}