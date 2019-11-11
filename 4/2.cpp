#include <iostream>
using namespace std;

// największy wspólny dzielnik - skopiowane z internetu
int gcd(int a, int b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
}

class ulamek {
    int licznik, mianownik;
    public:
    ulamek(int licznik, int mianownik)
        : licznik(licznik), mianownik(mianownik) {}
    ulamek shortened() const { // skracanie ułamka
        auto gcd_val = gcd(licznik, mianownik);
        return { licznik / gcd_val, mianownik / gcd_val };
    }
    ulamek operator * (const ulamek& other) const {
        return ulamek { 
            licznik * other.licznik,
            mianownik * other.mianownik 
        }.shortened(); // wywołanie metody obiektu tymczasowego
                       // - nie przypisanego do żadnej zmiennej
    }
    void print() {
        cout << licznik << '/' << mianownik << endl;
    }
};

int main() {
    ulamek ul = { 1, 2 };
    ul = ul * ulamek{ 2, 3 };
    ul.print(); // 1/3
}