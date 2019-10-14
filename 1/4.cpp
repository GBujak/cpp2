/**
 * Aplikacja konsolowa zmieniająca kilogramy na funty angielskie. Program
 * wykorzystuje tylko jedną klasę zawierającą tylko jedno statyczne pole.
 * Komunikaty wyświetlane w programie głównym.
 */

#include <iostream>
using namespace std;

class stale_matematyczne {
    public:
    static double pounds_in_kilogram;
};
double stale_matematyczne::pounds_in_kilogram = 2.20462262;

class kilogram {
    static long unsigned kilograms;
public:
    long unsigned& operator*() { return kilograms; }
    double get_pounds() { return kilograms * stale_matematyczne::pounds_in_kilogram; }
};
long unsigned kilogram::kilograms;

int main() {
    long unsigned kilograms;
    kilogram kg;
    while (cin) {
        cout << "Podaj kilogramy: ";
        cin >> *kg;
        cout << "Funty: " << kg.get_pounds() << endl;
    }
}