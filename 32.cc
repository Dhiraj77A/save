#include <iostream>
using namespace std;

// Item structure outside main
struct Item {
    string name;
    int qty;
    double price;
};

int main() {
    Item items[] = {
        {"Rice", 2, 55.75},
        {"Milk", 5, 25.40},
        {"Soap", 4, 30.00}
    };
    int n = sizeof(items)/sizeof(items[0]);
    double total = 0;

    cout << "------ Department Store Bill ------\n";
    cout.width(10); cout << "Item";
    cout.width(6);  cout << "Qty";
    cout.width(8);  cout << "Price";
    cout.width(10); cout << "Total\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < n; i++) {
        double t = items[i].qty * items[i].price;
        total += t;
        cout.width(10); cout << items[i].name;
        cout.width(6);  cout << items[i].qty;
        cout.width(8);  cout.precision(2); cout.setf(ios::fixed); cout << items[i].price;
        cout.width(10); cout << t << endl;
    }

    cout << "-----------------------------------\n";
    cout << "Grand Total: " << total << endl;
    cout << "Thank you for shopping!\n";
    return 0;
}