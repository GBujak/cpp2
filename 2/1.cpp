#include <list>
#include <iostream>
#include <string>

class stack {
    std::list<std::string> values;
    public:
    std::string top() { 
        return (this->values.size() == 0) 
                    ? "-- empty --" 
                    : this->values.back(); 
    }
    void push(std::string val) { this->values.push_back(val); }
    std::string pop() {
        std::string tmp = top();
        if (this->values.size() != 0) 
            this->values.pop_back();
        return tmp;
    }
};

int main() {
    stack s;

    while (std::cin) { // Pętla wykonywana do czasu gdy nie poda się
                       // znaku końca pliku ( Crtl + d )
        std::string line;
        std::getline(std::cin, line);
        if (line.length() == 0) exit(0);
        switch (line[0]) {
        case 'a':
            s.push({ line.begin() + 2, line.end() }); // Jeden z konstruktorów std::string
                                                      // przyjmuje dwa iteratory i tworzy
                                                      // nowy ciąg znaków z tych pomiędzy
                                                      // tymi iteratorami
            break;
        case 'p':
            std::cout << "Top:\n\t" << s.top() << std::endl;
            break;        
        case 'r':
            std::cout << "Removed:\n\t" << s.pop() << std::endl;
            break;
        default:
            exit(0);
            break;
        }
    }
}