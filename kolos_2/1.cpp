#include <iostream>
using namespace std;

void sprawdz_ilosc_kamizelek(int kamizelki, int kajakarze) {
    if (kamizelki < kajakarze) throw kajakarze - kamizelki;
}

int main() {
    int kamizelki, kajakarze;
    cout << "Podaj ilość kajakarzy: ";
    cin >> kajakarze;
    cout << "Podaj ilość kamizelek: ";
    cin >> kamizelki;

    try {
        sprawdz_ilosc_kamizelek(kamizelki, kajakarze);
        cout << "dobra ilosc kamizelek!" << endl;
    } catch (int blad) {
        cout << "Za malo kamizelek! Brakuje " << blad << " kamizelek" << endl;
    } 
}