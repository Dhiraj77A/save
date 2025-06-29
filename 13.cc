#include<iostream>
#include<cstring>
using namespace std;
class words{
    public:
    char *ch;

    public:
    words(): ch(nullptr){}
    words(const char *w1){
        int len=strlen(w1);
        ch=new char[len+1];
        strcpy(ch,w1);
    }
    void display(){
        cout<<"concatenated string: "<<ch<<endl;
    }
    ~words(){
        delete[]ch;
        cout<<"memory freed"<<endl;
    }


};

char* concatenate(char *ch1,char *ch2){
        int n=strlen(ch1)+strlen(ch2)+1;
        char *ptr=new char[n];
        int j=0,i=0;
        while(ch1[i]!='\0'){
            ptr[j++]=ch1[i++];
        }
        i=0;
        while(ch2[i]!='\0'){
            ptr[j++]=ch2[i++];
        }
        ptr[j]='\0';
        return  ptr;
}
int main(){
    words w1("engineers are");
    words w2("creates of logic");
   
    char* combined=concatenate(w1.ch,w2.ch);
    words w3(combined);
    w3.display();

    return 0;
}