#include <iostream>
using namespace std;
class calculator;
class coordinate;
class friendClass;

coordinate subtraction (const coordinate&a,const calculator&b);
coordinate multiplication (const coordinate&a,const calculator&b);
coordinate division (const coordinate&a,const calculator&b);
class coordinate{
    private:
    int x;
    int y;
    void secretMessage() const {
        cout << "[coordinate] Secret private function accessed!" << endl;
    }

    public:
    coordinate(int a=0,int b=0){
        x=a;
        y=b;
    }
    
    void display(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    friend friendClass;
    coordinate add(const calculator&a, const coordinate&b);
    friend coordinate subtraction (const coordinate&a,const calculator&b);
    friend coordinate multiplication (const coordinate&a,const calculator&b);
    friend coordinate division (const coordinate&a,const calculator&b);
};

class calculator{
    private:
    int x;
    int y;

    public:
    calculator(int a=0,int b=0){
        x=a;
        y=b;
    }

    void display(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }

    friend coordinate coordinate::add( const calculator&a, const coordinate&b);
    friend coordinate subtraction (const coordinate&a,const calculator&b);
    friend coordinate multiplication (const coordinate&a,const calculator&b);
    friend coordinate division (const coordinate&a,const calculator&b);
};
class friendClass{
    public:
    void showPrivate(const coordinate& c) {
        cout << "[friendClass] Accessing private data: (" << c.x << "," << c.y << ")" << endl;
        c.secretMessage(); 
    }

};
coordinate coordinate::add(const calculator&a, const coordinate&b){
    return coordinate(a.x+b.x,a.y+b.y);
}
coordinate subtraction (const coordinate&a,const calculator&b){
    return coordinate(a.x-b.x,a.y-b.y);
}
coordinate multiplication (const coordinate&a,const calculator&b){
    return coordinate(a.x*b.x,a.y*b.y);
}
coordinate division (const coordinate&a,const calculator&b){
    if(b.x==0||b.y ==0) return -1;
    return coordinate(a.x/b.x,a.y/b.y);
}

int main() {
    int x,y;
    cout<<"enter coordinate 1: ";
    cin>>x>>y;
    coordinate c1(x,y);
    cout<<"enter coordinate 2: ";
    cin>>x>>y;
    calculator c2(x,y);
    coordinate c3=c1.add(c2,c1);
    cout<<"addition: ";
    c3.display();
     c3=subtraction(c1,c2);
    cout<<"Subtraction: ";
    c3.display();
     c3=multiplication(c1,c2);
    cout<<"Multiplication: ";
    c3.display();
     c3=division(c1,c2);
    cout<<"Division: ";
    c3.display();
    friendClass f1;
    f1.showPrivate(c1);
    return 0;
}
