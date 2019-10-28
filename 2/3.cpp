#include <map>
#include <string>
#include <iostream>
#include <tuple>

using namespace std;

class dictionary {
    map<string, string> dict;
    public:
    void get_scan() {
        string eng, pol;
        cout << "angielski: "; cin >> eng;
        cout << "polski: ";    cin >> pol;
        dict[eng] = pol;
        // Operator [] na mapie konstruuje nową zmienną typu przechowy-
        // wanego w mapie i zwraca do niej referencję -> zmienia mapę !!!
    }
    void print() {
        for (auto i : dict)
            cout << i.first  << " -> "
                 << i.second << endl;
    }
    pair<bool, string> find(const string& eng) const {
        if (dict.find(eng) == dict.end()) 
            return { false, "" };
        // Metoda find zwraca iterator końcowy, gdy nie znajdzie podanej
        // wartości w mapie
        else return { true, dict.at(eng) };
        // Wywołanie metody "at" z kluczem, pod którym nie ma wartości
        // powoduje wyjątek -> wysypuje program
    }
};

int main() {
    dictionary d;

    while (cin) {
        char input = cin.get();
        string query;
        pair<bool, string> resp;

        switch (input) {
            case 'i':
                d.get_scan();
                break;
            case 'p':
                d.print();
                break;
            case 'f':
                cout << "Szukane słowo: ";
                cin >> query;
                resp = d.find(query);
                if (resp.first) cout << resp.second << endl;
                           else cout << "nie ma takiego słowa" << endl;
                break;

            case '\n': break;
            // enter wczytywany co drugi znak 

            default:
                cout << "exiting" << endl;
                exit(0);
        }
    }
}
