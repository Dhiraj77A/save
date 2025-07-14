#include<iostream>
using namespace std;

class subcmpx;

class complex {
protected:
    int real;
    int cmpx;

public:
    void getdata() {
        cout << "Enter the base real and complex part: ";
        cin >> real >> cmpx;
    }
};

class addcmpx : public complex {
protected:
    int real1;
    int cmpx1;

public:
    void getdata() {
        cout << "Enter the derived real and complex part: ";
        cin >> real1 >> cmpx1;
    }

    void show() {
        cout << "Addition: " << real1 + real << "+" << cmpx1 + cmpx << "i" << endl;
    }

    friend class subcmpx;
};

class subcmpx {
private:
    int real2;
    int cmpx2;

public:
    void getdata() {
        cout << "Enter the friend class real and complex part: ";
        cin >> real2 >> cmpx2;
    }

    void show(addcmpx c) {
        cout << "Subtraction: " << c.real - real2 << "+" << c.cmpx - cmpx2 << "i" << endl;
    }
};

int main() {
    
    addcmpx c2;
    c2.complex::getdata(); // base part
    c2.getdata();          // derived part
    c2.show();

    subcmpx c3;
    c3.getdata();
    c3.show(c2);

    return 0;
}
