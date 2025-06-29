#include<iostream>
using namespace std;
class Prime{
    private:
    int num;

    public:
    Prime(int n){
        num=n;
    }

    bool checkPrime(){
        if(num==0||num==1) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
};
int main(){
    int n;
    char choice;
    do{
        cout<<"Enter the number: ";
        cin>>n;
        Prime check(n);
        if(check.checkPrime()){
            cout<<"Prime Number "<<endl;
        }else{
            cout<<"Non Prime "<<endl;
        }
        cout<<"do you want to continue(y-for yes): ";
        cin>>choice;
    }while(choice=='y');
    return 0;
}
