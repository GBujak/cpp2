#include <iostream>

template <typename T>
class stack_t {
    class stack_node {
        T val;
        stack_node* next = nullptr;
        public:
        stack_node(stack_node* n, T val): next(n), val(val) {}
        T& operator*() { return val; }
        stack_node* delete_next() {
            auto tmp = next;
            delete this;
            return tmp;
        }
    };
    stack_node* top;
    unsigned height = 0;
    public:
    T get() { return **top; }
    T pop() {
        auto tmp = get();
        top = top->delete_next();
        return tmp;
        height--;
    }
    void push(T val) {
        top = new stack_node { top, val };
        height++;
    }
};

int main(void) {
    stack_t<int> s;
    for (int i = 0; i < 100; i++) s.push(i);
    for (int i = 0; i < 100; i++) std::cout << s.pop() << " ";
    std::cout << std::endl;

    stack_t<std::string> string_stack;
    string_stack.push("test");
    string_stack.push("test2");
    string_stack.push("test3");
    string_stack.push("test4");
    for (int i = 0; i < 4; i++) std::cout << string_stack.pop() << std::endl;
}