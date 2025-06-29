#include<iostream>
using namespace std;

class overload{
    private:
    int num;

    public:
    overload(int x=0){
        num=x;
    }

    bool operator ==(const overload&a){
        return num==a.num;
    }
    bool operator >(const overload&a){
        return num>a.num;
    }
    bool operator <(const overload&a){
        return num<a.num;
    }
    bool operator !=(const overload&a){
        return num!=a.num;
    }
    bool operator >=(const overload&a){
        return num>=a.num;
    }
    bool operator <=(const overload&a){
        return num<=a.num;
    }
};

int main(){
    int x,y;
    cout<<"Enter the two number: ";
    cin>>x>>y;
    overload num1(x);
    overload num2(y);
    cout<<"num1==num2: "<<(num1==num2)<<endl;
    cout<<"num1>num2: "<<(num1>num2)<<endl;
    cout<<"num1<num2: "<<(num1<num2)<<endl;
    cout<<"num1!=num2: "<<(num1!=num2)<<endl;
    cout<<"num1>=num2: "<<(num1>=num2)<<endl;
    cout<<"num1<=num2: "<<(num1<=num2)<<endl;
    return 0;
}