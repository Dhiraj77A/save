#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class overloadIndex{
    private: 
    int arr[50];

    public:
    overloadIndex(){
        for(int i=0;i<50;i++){
        arr[i]=(i+1)*2;
    }
    }

    int& operator[](const int& idx){
        if(idx<0||idx>=50){
            cout<<"you are trying to access index the is out of bound: error"<<endl;
            exit(1);
        }
        return arr[idx];
    }
};

class overloadNewDelete{
    public:

    overloadNewDelete(){
        cout<<"allows only compile time memory allocation(no use of new and delete)"<<endl;
    }
    void* operator new(size_t)=delete;
    void operator delete(void *)=delete;
};

class overloadAssignment{
    private: 
    char *ptr;

    public:
    overloadAssignment(const char*str=""){
        ptr=new char[strlen(str)+1];
        strcpy(ptr, str);
    }

    overloadAssignment& operator=(const overloadAssignment& cpystr){
        if(this!=&cpystr){
            delete[] ptr;
            ptr=new char[strlen(cpystr.ptr)+1];
            strcpy(ptr,cpystr.ptr);
        }
        return *this;
    }
    void print() {
        cout << ptr << endl;
    }

    ~overloadAssignment(){
        delete [] ptr;
    }
};

class overloadCall{
    public:
    void operator ()(const char* string){
        for(int i=strlen(string)-1;i>=0;i++){
            cout<<string[i];
        }
        cout<<endl;
    }
};

int main(){
    overloadIndex data1;
    int idx;
    cout<<"Enter the index you want to access: ";
    cin>>idx;
    cout<<"element at idx "<<idx<<" is "<<data1[idx]<<endl;

    overloadNewDelete obj1;
    //overloadNewDelete* ptr=new int[24];
    //delete [] ptr;
    char word[50];
    cout<<"Enter the str: ";
    cin>>word;
    overloadAssignment string1(word);
    overloadAssignment strcpy;
    strcpy=string1;
    cout<<"copied string: ";
    strcpy.print();

    cout<<"enter any string: ";
    cin>>word;
    overloadCall reverse;
    cout<<"reverse of word: ";
    reverse(word);
    return 0;
}