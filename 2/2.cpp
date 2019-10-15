#include <set>
#include <iostream>
#include <string>

using namespace std;

class student {
    string name;
    string surname;
    friend student scan_student();
public:
    student(string name, string surname)
        : name(name), surname(surname) {}
    student() = default;

    // Bez tego nie można umieszczać elementów w zbiorze bo elementy zbioru są
    // posortowane, więc musi dać się je porównać
    bool operator<(const student& other) const {
        return surname < other.surname;
    };

    string str() const { return surname + " " + name; }
};

student scan_student() {
    student s;
    cout << "Imię: ";
    cin >> s.name;
    cout << "Nazwisko: ";
    cin >> s.surname;
    return s;
}

int main(void) {
    set<student> s;

    while (cin) {
        char input = cin.get();
        switch (input) {
            case 'i':
                s.insert(scan_student());
                break;
            case 'p':
                for (const student& st : s)
                    cout << st.str() << endl;
                break;
            case '\n': break;
            default:
                cout << "exiting" << endl;
                exit(0);
                break;
        }
    }
}