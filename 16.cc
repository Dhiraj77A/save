#include <iostream>
using namespace std;

class Calculator; // Forward declaration

class Point2D {
private:
    double x, y;
public:
    Point2D(double a=0, double b=0) : x(a), y(b) {}

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // Only addPoints is a friend, not the whole Calculator
    friend Point2D Calculator::addPoints(const Point2D&, const Point2D&);

    // Demonstrate all member functions of Calculator are friends
    friend class AllFriendCalculator;
};

class Calculator {
public:
    // A. Friend function (declared as friend in Point2D)
    Point2D addPoints(const Point2D &p1, const Point2D &p2) {
        // Accessing private members of Point2D
        return Point2D(p1.x + p2.x, p1.y + p2.y);
    }

    // B. Bridge functions (work as normal member functions, not friends)
    Point2D multiply(const Point2D &p1, const Point2D &p2) {
        return Point2D(p1.x * p2.x, p1.y * p2.y);
    }
    Point2D divide(const Point2D &p1, const Point2D &p2) {
        return Point2D(p1.x / p2.x, p1.y / p2.y);
    }
    Point2D subtract(const Point2D &p1, const Point2D &p2) {
        return Point2D(p1.x - p2.x, p1.y - p2.y);
    }
};

// C. All member functions of this class are friends of Point2D
class AllFriendCalculator {
public:
    void showPrivate(const Point2D &p) {
        cout << "Accessing private x: " << p.x << ", y: " << p.y << endl;
    }
};

int main() {
    Point2D p1(2, 3), p2(4, 1);
    Calculator calc;

    cout << "p1: "; p1.display();
    cout << "p2: "; p2.display();

    // A. Addition using friend function
    Point2D sum = calc.addPoints(p1, p2);
    cout << "Addition (friend): "; sum.display();

    // B. Bridge functions (multiplication, division, subtraction)
    Point2D product = calc.multiply(p1, p2);
    cout << "Multiplication (bridge): "; product.display();

    Point2D quotient = calc.divide(p1, p2);
    cout << "Division (bridge): "; quotient.display();

    Point2D difference = calc.subtract(p1, p2);
    cout << "Subtraction (bridge): "; difference.display();

    // C. Demonstrate class friendship
    AllFriendCalculator afc;
    cout << "AllFriendCalculator accessing private members of p1: ";
    afc.showPrivate(p1);

    return 0;
}