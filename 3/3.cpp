#include <iostream>
#include <list>
#include <tuple>

template <typename T>
class list {
    class list_node {
        list_node* next;
        T val;
        public:
        list_node(list_node* next, T val)
            : next(next), val(val) {}
        T& get_ref() { return val; }
        list_node get_next() { return next; }
    };
    list_node node = nullptr;
    public:
    void add(T val) { node = { node, val }; }
    
};

int main(void) {

}