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
    }
    void print() {
        for (auto i : dict)
            cout << get<0>(i) << " -> "
                 << get<1>(i) << endl;
    }
    pair<bool, string> find(const string& eng) const {
        if (dict.find(eng) == dict.end()) return { false, "" };
        else return { true, dict.at(eng) };
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

            // enter wczytywany co drugi znak 
            case '\n': break;

            default:
                cout << "exiting" << endl;
                exit(0);
                break;
        }
    }
}
