#include<iostream>
using namespace std;
class coordinate{
    private:
    int x;
    int y;
    int z;

    public:
    coordinate(int a=0,int b=0,int c=0){
        x=a;
        y=b;
        z=c;
    }

    friend coordinate operator +(const coordinate&a, const coordinate&b);
    friend coordinate operator -(const coordinate&a, const coordinate&b);

    void showdata(){
        cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
    }
};

coordinate operator +(const coordinate&a, const coordinate&b){
    return coordinate(a.x+b.x,a.y+b.y,a.z+b.z);
    
}
coordinate operator -(const coordinate&a, const coordinate&b){
    return coordinate(a.x-b.x,a.y-b.y,a.z-b.z);
}

int main(){
    int x,y,z;
    cout<<"Enter the x,y,and z coordinate(1): ";
    cin>>x>>y>>z;
    coordinate c1(x,y,z);
    cout<<"Enter the x,y,and z coordinate(2): ";
    cin>>x>>y>>z;
    coordinate c2(x,y,z);
    coordinate c3=c1+c2;
    cout<<"Add: "<<endl;
    c3.showdata();
    c3=c1-c2;
    cout<<"Subtract: "<<endl;
    c3.showdata();
    return 0;
}