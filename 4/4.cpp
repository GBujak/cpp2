#include <iostream>
using namespace std;

class vec3d {
    int x, y, z;
    public:
    vec3d(int x, int y, int z)
        : x(x), y(y), z(z) {}
    bool operator==(const vec3d& other) const {
        if (x != other.x
         || y != other.y
         || z != other.z) return false;
        else return true;
    }
    bool operator!=(const vec3d& other) const {
        return !(*this == other); // dereferencja wskaźnika "this" -
                                  // operator "==" nie spodziewa się
                                  // wskaźnika, tylko wartości
                                  // można to też zrobić:
                                  // !this->operator==(other);
    }
};

int main(void) {
    vec3d vec1 = {1, 2, 3};
    vec3d vec2 = {1, 2, 4};
    cout << "vec1 == vec1: " << (vec1 == vec1) << endl;
    cout << "vec1 != vec1: " << (vec1 != vec1) << endl;
    cout << "vec1 == vec2: " << (vec1 == vec2) << endl;
    cout << "vec1 != vec2: " << (vec1 != vec2) << endl;
}