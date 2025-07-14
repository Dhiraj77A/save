#include<iostream>
using namespace std;

class Musicians {
protected:
    string str[5];
    string wind[5];
    string perc[5];

public:
    void stringInstruments() {
        str[0] = "Veena";
        str[1] = "Guitar";
        str[2] = "Sitar";
        str[3] = "Sarod";
        str[4] = "Mandolin";

        cout << "\nString Instruments:\n";
        for (int i = 0; i < 5; i++) {
            cout << "- " << str[i] << endl;
        }
    }

    void windInstruments() {
        wind[0] = "Flute";
        wind[1] = "Clarinet";
        wind[2] = "Saxophone";
        wind[3] = "Nadaswaram";
        wind[4] = "Piccolo";

        cout << "\nWind Instruments:\n";
        for (int i = 0; i < 5; i++) {
            cout << "- " << wind[i] << endl;
        }
    }

    void percussionInstruments() {
        perc[0] = "Tabla";
        perc[1] = "Mridangam";
        perc[2] = "Bangos";
        perc[3] = "Drums";
        perc[4] = "Tambour";

        cout << "\nPercussion Instruments:\n";
        for (int i = 0; i < 5; i++) {
            cout << "- " << perc[i] << endl;
        }
    }
};

// Derived class
class TypeIns : public Musicians {
private:
    int choice;

public:
    void get() {
        cout << "\nType of instruments to be displayed\n";
        cout << "1. String instruments\n";
        cout << "2. Wind instruments\n";
        cout << "3. Percussion instruments\n";
        cout << "Enter your choice: ";
        cin >> choice;
    }

    void show() {
        switch (choice) {
            case 1:
                stringInstruments();
                break;
            case 2:
                windInstruments();
                break;
            case 3:
                percussionInstruments();
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
};

// Main function
int main() {
    TypeIns t;
    t.get();
    t.show();
    return 0;
}
