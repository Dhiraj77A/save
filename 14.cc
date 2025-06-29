#include<iostream>
#include<cstring>
using namespace std;
class department{
    private:
    int depid;
    char departname[50];
    public:
    
    department(int n=0, const char* name="nothing"){
        depid=n;
        strcpy(departname,name);
    }
    void showdata(){
        cout<<"department id: "<<depid<<"\t"<<"department name: "<<departname<<endl;
    }
    ~department(){
        static int i=1;
        cout<<"object "<<i<<" goes out of the scope"<<endl;
        i++;
    }
};
int main(){
    int n;
    cout<<"Enter the number of department: ";
    cin>>n;
    department*ptr =new department[n];
    int id;
    char name[50];
    for(int i=0;i<n;i++){
        cout<<"Enter the department id: ";
        cin>>id;
        cout<<"Enter the department name: ";
        cin>>name;
        
        ptr[i]=department(id,name);
    }
    for(int i=0;i<n;i++){
        ptr[i].showdata();
    }
    return 0;
}