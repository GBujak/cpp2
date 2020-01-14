/*
 * Zadanie 1. 
 * Napisać program z wykorzystaniem przeciążonego operatora
 * dzielenia, jako niezależnej operatorowej funkcji globalnej zaprzyjaźnionej z
 * daną klasą, który umożliwi dzielenie dwóch ułamków oraz zwróci ułamek będący
 * ilorazem tych ułamków. Korzystając z obsługi wyjątków, zabezpieczyć program
 * przed dzieleniem przez zero.
 */

#include <iostream>
#include <string>
using namespace std;

class ulamek {
    int licznik, mianownik;
    public:
    ulamek(int licznik, int mianownik)
        : licznik(licznik), mianownik(mianownik) {}
    void print() {
        cout << "Ulamek: " << licznik << " / " << mianownik << endl;
    }
    friend ulamek operator/(ulamek lewy, ulamek prawy);
};

ulamek operator/(ulamek lewy, ulamek prawy) {
    if (prawy.licznik == 0) throw "dzielenie przez zero!";
    lewy.licznik   *= prawy.mianownik;
    lewy.mianownik *= prawy.licznik;
    return lewy;
}

int main() {
    try {
        ulamek pierwszy = ulamek{1, 3} / ulamek{2, 3};
        pierwszy.print();
        ulamek drugi = ulamek{1, 5} / ulamek{0, 5};
    } catch (const char* exc) {
        cout << "Wyjątek: " << exc << endl;
    }
}