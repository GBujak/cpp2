#include <iostream>
using namespace std;

int main() {
    int kamizelki, kajakarze;
    cout << "Podaj ilość kajakarzy: ";
    cin >> kajakarze;
    cout << "Podaj ilość kamizelek: ";
    cin >> kamizelki;

    if (kamizelki < kajakarze) {
        cout << "Uwaga, za mało kamizelek!" << endl;
        cout << "Brakuje " << kajakarze - kamizelki << " kamizelek" << endl;
    } else {
        cout << "Wystarczy kamizelek" << endl;
    }
}