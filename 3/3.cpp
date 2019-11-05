#include <list>
#include <string>
#include <iostream>

template <typename T>
class list_t {
    std::list<T> m_list;
    public:
    void print() {
        for (auto i : m_list)
            std::cout << i << ", ";
        std::cout << std::endl;
    }
    void push(T val) {
        m_list.push_back(val);
    }
};

int main() {
    list_t<std::string> string_list;
    string_list.push("Hello");
    string_list.push("world!");
    string_list.print();
    
    list_t<int> int_list;
    int_list.push(10);
    int_list.push(20);
    int_list.print();

    list_t<float> float_list;
    float_list.push(10.123);
    float_list.push(20.123);
    float_list.print();
}
