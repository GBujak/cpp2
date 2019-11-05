#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <typename T>
void bubblesort(vector<T>& vec) {
    bool changes = true;
    while (changes) {
        changes = false;
        for (auto it = vec.begin(); it != vec.end() - 1; it++) {
            if (*it > *(it + 1)) {
                swap(*it, *(it + 1));
                changes = true;
            }
        }
    }
}

template <typename T>
void insertionsort(vector<T>& vec) {
    typename vector<T>::iterator j;
    for (auto i = vec.begin()+1; i != vec.end(); i++) {
        auto temp = *i;
        for (j = i - 1; j != vec.begin() - 1 && *j > temp; j--)
            *(j + 1) = *j;
        *(j + 1) = temp;
    }
}

int main() {
    vector<int> vec = {23, 43, 346, 657, 12, 1, 65, 89, 2};
    bubblesort(vec);
    for (auto i: vec) cout << i << ", "; cout << endl;

    vector<int> vec2 = {23, 43, 346, 657, 12, 1, 65, 89, 2};
    insertionsort(vec2);
    for (auto i: vec2) cout << i << ", "; cout << endl;
}
