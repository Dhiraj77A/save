#include<iostream>
using namespace std;
class american;

class  metric{
    private:
    int meter;
    int centi;

    public:
    metric(int m=0, int c=0){
        meter=m;
        centi=c;
    }
    friend class american;
    void display(){
        cout<<"meter: "<<meter<<endl;
        cout<<"centimeter: "<<centi<<endl;

    }

};
class american{
    private:
    int feet;
    int inches;

    public:
    american(int f=0, int i=0){
        feet=f;
        inches=i;
        if (inches >= 12) {
    feet += inches / 12;
    inches = inches % 12;
}

    }

    american( metric m){
        float c1=m.meter+m.centi/100.00;
        float c2=c1*3.28;
        feet=static_cast<int>(c2);
        inches=static_cast<int>((c2-feet)*12);
    }

    operator metric(){
        float c1=feet+inches/12.00;
        float c2=c1/3.28;
        return metric(static_cast<int>(c2),static_cast<int>((c2-static_cast<int>(c2))*100));

    }
    void display(){
        cout<<"feet: "<<feet<<endl;
        cout<<"inches: "<<inches<<endl;

    }
};
int main(){
    int f,i,m,c;
    cout<<"Enter meter and centimeter: ";
    cin>>m>>c;
    metric m1(m,c);
    american a1(m1);
    a1.display();
    cout<<"Enter feet and inches: ";
    cin>>f>>i;
    american a2(f,i);
    metric m2=(metric)a2;
    m2.display();
    return 0;
}