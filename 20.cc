#include<iostream>
using namespace std;

class sample {
public:
    void nonconst() {
        cout << "non const function called\n";
    }

    void constfunc() const {   // <-- const member function
        cout << "const function called\n";
    }
};

int main() {
    const sample constobj;
    sample nonconstobj;

    // constobj.nonconst();   // ERROR: cannot call non-const func on const object
    constobj.constfunc();     // OK
    nonconstobj.constfunc();  // OK
    nonconstobj.nonconst();   // OK

    return 0;
}
