#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class overloadIndex{
    private:
        int arr[50];
    public:
        overloadIndex(){
            for(int i=0; i<50; i++){
                arr[i]=(i+1)*2;
            }
        }
        
        int& operator[](const int& idx){
            if(idx<0 || idx>=50){
                cout<<"You are trying to access index that is out of bound: error"<<endl;
                exit(1);
            }
            return arr[idx];
        }
};

class overloadNewDelete{
    public:
        overloadNewDelete(){
            cout<<"Allows only compile time memory allocation (no use of new and delete)"<<endl;
        }
        
        // Delete new and delete operators to prevent dynamic allocation
        void* operator new(size_t) = delete;
        void operator delete(void*) = delete;
};

class overloadAssignment{
    private:
        char *ptr;
    public:
        overloadAssignment(const char* str = ""){
            ptr = new char[strlen(str)+1];
            strcpy(ptr, str);
        }
        overloadAssignment& operator=(const overloadAssignment& cpystr){
            if(this != &cpystr){
                delete[] ptr;
                ptr = new char[strlen(cpystr.ptr)+1];
                strcpy(ptr, cpystr.ptr);
            }
            return *this;
        }
        
        void print() {
            cout << ptr << endl;
        }
        
        ~overloadAssignment(){
            delete[] ptr;
        }
};

class overloadCall{
    public:
        void operator()(const char* string){
            cout << "Reverse of word: ";
            for(int i = strlen(string)-1; i >= 0; i--){
                cout << string[i];
            }
            cout << endl;
        }
};

class overloadLogical{
    private:
    bool status;

    public:
    overloadLogical(bool val = false) : status(val) {}

    bool operator !() const{
        return !status;
    }

    overloadLogical operator&&(const overloadLogical& other) const {
        return overloadLogical(!(status && other.status));
    }

    overloadLogical operator||(const overloadLogical& other) const {
        return overloadLogical(!(status || other.status));
    }

    void print()  {
        cout << (status ? "True" : "False") << endl;
    }
};

class overloadBitwise {
private:
    int value;

public:
    // Constructor
    overloadBitwise(int val = 0) : value(val) {}

    // Bitwise AND operator
    overloadBitwise operator&(const overloadBitwise& other) const {
        return overloadBitwise(value & other.value);
    }

    // Bitwise OR operator
    overloadBitwise operator|(const overloadBitwise& other) const {
        return overloadBitwise(value | other.value);
    }

    // Bitwise XOR operator
    overloadBitwise operator^(const overloadBitwise& other) const {
        return overloadBitwise(value ^ other.value);
    }

    // Bitwise NOT operator
    overloadBitwise operator~() const {
        return overloadBitwise(~value);
    }

    // Left shift operator
    overloadBitwise operator<<(int shift) const {
        return overloadBitwise(value << shift);
    }

    // Right shift operator
    overloadBitwise operator>>(int shift) const {
        return overloadBitwise(value >> shift);
    }

    // Print the value
    void print() const {
        cout << "Value: " << value << endl;
    }
};

int main(){
    overloadIndex data1;
    int idx;
    cout << "Enter the index you want to access (0-49): ";
    cin >> idx;
    cout << "Element at index " << idx << " is " << data1[idx] << endl;
    
    overloadNewDelete obj1;
    // The following lines would cause compilation error (which is intended)
    // overloadNewDelete* ptr = new overloadNewDelete();
    // delete ptr;
    
    char word[50];
    cout << "Enter the string: ";
    cin.ignore();
    cin.getline(word, 50);
    
    overloadAssignment string1(word);
    overloadAssignment strcpy;
    strcpy = string1;
    cout << "Copied string: ";
    strcpy.print();
    

    char str[50];
    cout << "Enter any string: ";
    cin.getline(str, 50);
    
    overloadCall reverse;
    reverse(str);

    overloadLogical a(true);
    overloadLogical b(false);

    cout << "NOT b: " << (!b ? "True" : "False") << endl;

    overloadLogical nandResult = a && b; 
    cout << "NAND (a && b): ";
    nandResult.print();

    overloadLogical norResult = a || b;  
    cout << "NOR (a || b): ";
    norResult.print();
    
    overloadBitwise data2(5);  // Binary: 0101
    overloadBitwise data3(3);  // Binary: 0011

    // Bitwise AND
    overloadBitwise andResult = data2 & data3;
    cout << "Bitwise AND: ";
    andResult.print();

    // Bitwise OR
    overloadBitwise orResult = data2 | data3;
    cout << "Bitwise OR: ";
    orResult.print();

    // Bitwise XOR
    overloadBitwise xorResult = data2 ^ data3;
    cout << "Bitwise XOR: ";
    xorResult.print();

    // Bitwise NOT
    overloadBitwise notResult = ~data2;
    cout << "Bitwise NOT: ";
    notResult.print();

    // Left Shift
    overloadBitwise shiftLeft = data2 << 1;  // Shift left by 1
    cout << "Left Shift by 1: ";
    shiftLeft.print();

    // Right Shift
    overloadBitwise shiftRight = data2 >> 1;  // Shift right by 1
    cout << "Right Shift by 1: ";
    shiftRight.print();  // <-- Missing semicolon fixed here

    return 0;
}
