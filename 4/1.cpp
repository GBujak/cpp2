#include <iostream>

using namespace std;

class vec2d {
    int x, y;
    public:
    vec2d(int x, int y)
        : x(x), y(y) {}
    vec2d operator+(const vec2d& other) const {
        return {x + other.x, y + other.y};
    }
    vec2d operator-(const vec2d& other) const {
        return {x - other.x, y - other.y};
    }
    void print() {
        cout << "x: " << x << " y: " << y << endl;
    }
};

int main() {
    vec2d vec1 = {5, 10};
    auto vec2 = vec1 + vec2d{12, 453};
    vec2 = vec2 - vec2d{12, 451};
    vec2.print();
}