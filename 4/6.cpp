#include <iostream>
#include <string>
using namespace std;

class string_container {
    string val;
    public:
    string_container(string val)
        : val(val) {}
    string_container(const string_container& other)
        : val(other.val) {} // konstruktor zostanie wywołany przy przypisaniu (=)
    string& get() { return val; }
};

int main() {
    string_container cont1{"test"};
    string_container cont2 = cont1;
    cont1.get() = "Hello";
    cout << "cont1: " << cont1.get() << endl;
    cout << "cont2: " << cont2.get() << endl; // string został skopiowany - wartości się różnią
}