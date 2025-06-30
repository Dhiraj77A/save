#include<iostream>
#include<cstring>
using namespace std;
class words{
    private:
    char *ch;

    public:
    words(): ch(nullptr){}
    words(const char *w1){
        int len=strlen(w1);
        ch=new char[len+1];
        strcpy(ch,w1);
    }
    words& operator +=(const words&str1){
        int n=strlen(str1.ch)+strlen(ch)+1;
        char * newSpace=new char[n];
        int j=0,i=0;
        while(ch[i]!='\0'){
            newSpace[j++]=ch[i++];
        }
        i=0;
        while(str1.ch[i]!='\0'){
            newSpace[j++]=str1.ch[i++];
        }
        newSpace[j]='\0';
        delete []ch;
        ch=newSpace;
        return  *this;
}
    void display(){
        cout<<"concatenated string: "<<ch<<endl;
    }
    ~words(){
        delete[]ch;
        cout<<"memory freed"<<endl;
    }
};



int main(){
    words w1("engineers are");
    words w2("creates of logic");
    w1+=w2;
    w1.display();

    return 0;
}