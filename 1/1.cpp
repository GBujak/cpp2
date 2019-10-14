/**
 * Aplikacja konsolowa zmieniająca kilogramy na funty angielskie
 */

#include <iostream>
using namespace std;

double kg_to_pounds(long unsigned kilograms) {
    return kilograms * 2.20462262;
}

int main() {
    long unsigned kilograms;
    while (cin) {
        cout << "Podaj kilogramy: ";
        cin >> kilograms;
        cout << "Funty: " << kg_to_pounds(kilograms) << endl;
    }
}