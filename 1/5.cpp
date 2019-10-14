/**
 * Aplikacja konsolowa zmieniająca kilogramy na funty angielskie. Funkcjonalność
 * programu znajduje się w polach i metodach statycznychs klasy.
 */

#include <iostream>
using namespace std;

class kilogram {
    const static double przelicznik;
    static long unsigned kilograms;
public:
    kilogram(long unsigned kg) {
        kilograms = kg;
    }
    static double get_in_pounds() { return kilograms * przelicznik; }
    static void print_pounds() { cout << "Funty: " << get_in_pounds() << endl; }
};
long unsigned kilogram::kilograms;
const double kilogram::przelicznik = 2.20462262;

int main() {
    long unsigned kilograms;
    while (cin) {
        cout << "Podaj kilogramy: ";
        cin >> kilograms;
        kilogram kg_object { kilograms };
        kg_object.print_pounds();
    }
}