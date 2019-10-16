#include <iostream>
#include <random>
using namespace std;

template <class T>
void print_arr(T* arr, int size);

template <class T>
void _swap(T& a, T& b) {
    T tmp = b;
    b = a;
    a = tmp;
}

template <class T>
void bubblesort(T* array, int size) {
    bool changes = false;
    do {
        changes = false;
        for (int i = 1; i < size; i++) {
            if ( array[i-1] > array[i] ) {
                _swap<T>(array[i-1], array[i]);
                changes = true;
                // print_arr(array, size);
            }
        }
    } while (changes);
}

template <class T>
void print_arr(T* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << "]" << endl;
}

std::random_device r;
int main(void) {
    constexpr int size = 20;
    auto arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = r() % 100;
    print_arr(arr, size);
    bubblesort<int>(arr, size);
    print_arr(arr, size);
    delete[] arr;

    auto arrf = new float[size];
    for (int i = 0; i < size; i++)
        arrf[i] = (r() % 100) / 100.0f;
    print_arr(arrf, size);
    bubblesort(arrf, size);
    print_arr(arrf, size);
}