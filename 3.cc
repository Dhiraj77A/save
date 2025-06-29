#include<iostream>
using namespace std;
namespace square{
    int num;
    int fun(int n){
        return n*n;
    }
}
namespace cube{
    int num;
    int fun(int n){
        return n*n*n;
    }
}
int main(){
    square::num=7;
    cube::num=12;
    cout<<"Cube of square namespace num: "<<cube::fun(square::num)<<endl;
    cout<<"Square of cube namespace num: "<<square::fun(cube::num)<<endl;
    return 0;
}