#include <iostream>
#include <string>
using namespace std;

class time_class {
    unsigned hour, minute, second;
    public:
    time_class(unsigned hour, unsigned minute, unsigned second)
        : hour(hour), minute(minute), second(second) {}
    void operator= (const time_class& other) {
        hour = other.hour;
        minute = other.minute;
        second = other.second;
    }
    void print() {
        cout << hour << ':' << minute << ':' << second << endl;
    }
};

int main() {
    time_class cont1{12, 22, 00};
    time_class cont2 = cont1;
    cont1 = time_class{14, 53, 12};
    cont1.print();
    cont2.print();
}