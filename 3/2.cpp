#include <iostream>
#include <stack>
#include <string>

template <typename T>
class stack_t {
    std::stack<T> m_stack;
    public:
    T pop() {
        T val = m_stack.top();
        m_stack.pop();
        return val;
    }
    void push(T val) {
        m_stack.push(val);
    }
};

int main() {
    stack_t<std::string> string_stack;
    string_stack.push("Hello");
    string_stack.push("world");
    std::cout << string_stack.pop() 
       << " " << string_stack.pop() << std::endl;

    stack_t<int> int_stack;
    int_stack.push(10);
    int_stack.push(20);
    std::cout << int_stack.pop() 
       << " " << int_stack.pop() << std::endl;

    stack_t<float> float_stack;
    float_stack.push(10.123);
    float_stack.push(20.123);
    std::cout << float_stack.pop() 
       << " " << float_stack.pop() << std::endl;
}
