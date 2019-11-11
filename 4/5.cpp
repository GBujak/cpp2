#include <iostream>
using namespace std;

class vec3d {
    int x, y, z;
    public:
    vec3d(int x, int y, int z)
        : x(x), y(y), z(z) {}
    friend bool operator==(const vec3d& left, const vec3d& right);
    friend bool operator!=(const vec3d& left, const vec3d& right);
};

bool operator==(const vec3d& left, const vec3d& right) {
    if (left.x != right.x
     || left.y != right.y
     || left.z != right.z) return false;
    else return true;
}

bool operator!=(const vec3d& left, const vec3d& right) {
    return !( left == right );
}

int main(void) {
    vec3d vec1 = {1, 2, 3};
    vec3d vec2 = {1, 2, 4};
    cout << "vec1 == vec1: " << (vec1 == vec1) << endl;
    cout << "vec1 != vec1: " << (vec1 != vec1) << endl;
    cout << "vec1 == vec2: " << (vec1 == vec2) << endl;
    cout << "vec1 != vec2: " << (vec1 != vec2) << endl;
}