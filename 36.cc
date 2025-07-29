#include <iostream>
#include <fstream>
using namespace std;

struct Acct {
    int no;
    char ln[20];
    char fn[20];
    double bal;
};

const char* FN = "accounts.dat";

// Add account
void add() {
    Acct a;
    cout << "Account Number: ";
    cin >> a.no;
    cout << "Last Name: ";
    cin >> a.ln;
    cout << "First Name: ";
    cin >> a.fn;
    cout << "Total Balance: ";
    cin >> a.bal;

    ofstream out(FN, ios::binary | ios::app);
    out.write(reinterpret_cast<char*>(&a), sizeof(a));
    out.close();
    cout << "Added.\n";
}

// Display all accounts
void disp() {
    ifstream in(FN, ios::binary);
    Acct a;
    while (in.read(reinterpret_cast<char*>(&a), sizeof(a))) {
        if (a.no != 0) {
            cout << "\nAccNo: " << a.no
                 << "\nLast Name: " << a.ln
                 << "\nFirst Name: " << a.fn
                 << "\nBalance: " << a.bal << "\n";
        }
    }
    in.close();
}

// Update account
void upd() {
    int n;
    cout << "Account Number to update: ";
    cin >> n;

    fstream f(FN, ios::in | ios::out | ios::binary);
    Acct a;
    bool found = false;
    while (f.read(reinterpret_cast<char*>(&a), sizeof(a))) {
        if (a.no == n) {
            cout << "New Last Name: ";
            cin >> a.ln;
            cout << "New First Name: ";
            cin >> a.fn;
            cout << "New Balance: ";
            cin >> a.bal;
            f.seekp(-static_cast<int>(sizeof(a)), ios::cur);
            f.write(reinterpret_cast<char*>(&a), sizeof(a));
            found = true;
            cout << "Updated.\n";
            break;
        }
    }
    if (!found) cout << "Not found.\n";
    f.close();
}

// Delete account
void del() {
    int n;
    cout << "Account Number to delete: ";
    cin >> n;

    fstream f(FN, ios::in | ios::out | ios::binary);
    Acct a;
    bool found = false;
    while (f.read(reinterpret_cast<char*>(&a), sizeof(a))) {
        if (a.no == n) {
            a.no = 0; // mark deleted
            f.seekp(-static_cast<int>(sizeof(a)), ios::cur);
            f.write(reinterpret_cast<char*>(&a), sizeof(a));
            found = true;
            cout << "Deleted.\n";
            break;
        }
    }
    if (!found) cout << "Not found.\n";
    f.close();
}

int main() {
    int ch;
    do {
        cout << "\n1. Add\n2. Update\n3. Delete\n4. Display\n5. Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) add();
        else if (ch == 2) upd();
        else if (ch == 3) del();
        else if (ch == 4) disp();
    } while (ch != 5);
    return 0;
}