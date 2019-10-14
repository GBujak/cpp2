/**
 * Aplikacja konsolowa zmieniająca kilogramy na funty angielskie. Funkcjonalność
 * programu znajduje się w polach i metodach niestatycznych klasy.
 */

#include <iostream>
using namespace std;

class kilogram {
    long unsigned kilograms;
public:
    kilogram(long unsigned kilogram) : kilograms(kilogram) {}
    double get_in_pounds() { return kilograms * 2.20462262; }
    void print_pounds() { cout << "Funty: " << get_in_pounds() << endl; }
};

int main() {
    long unsigned kilograms;
    while (cin) {
        cout << "Podaj kilogramy: ";
        cin >> kilograms;
        kilogram kg_object { kilograms };
        kg_object.print_pounds();
    }
}