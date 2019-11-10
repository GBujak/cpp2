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
    ulamek shortened() const {
        auto gcd_val = gcd(licznik, mianownik);
        return { licznik / gcd_val, mianownik / gcd_val };
    }
    void print() {
        cout << licznik << '/' << mianownik << endl;
    }
    
    friend ulamek operator * (const ulamek&, const ulamek&);
};

ulamek operator * (const ulamek& first, const ulamek& second) {
    return ulamek { 
        first.licznik * second.licznik,
        first.mianownik * second.mianownik 
    }.shortened();
}

int main() {
    ulamek ul = { 1, 2 };
    ul = ul * ulamek{ 2, 3 };
    ul.print(); // 1/3
}