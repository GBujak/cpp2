#include <map>
#include <string>
#include <iostream>
#include <tuple>

using namespace std;

template <typename LEFT, typename RIGHT>
class dict_t {
    map<LEFT, RIGHT> m_dict;
    public:
    void print() const {
        for (const auto i : m_dict)
            cout << i.first << " - " << i.second << endl;
    }
    void add(LEFT eng, RIGHT pol) {
        m_dict[eng] = pol;
    }
    void find(LEFT q) const {
        if (m_dict.find(q) == m_dict.end())
             cout << "nie ma tłumaczenia" << endl;
        else cout << m_dict.at(q) << endl;
    }
};

int main(void) {
    dict_t<int, float> half_dict;
    for (int i = 0; i < 10; i++)
        half_dict.add(i, i / 2.0);
    half_dict.print();

    cout << "   =================================   "  << endl;

    dict_t<int, const char*> string_dict;
    for (int i = 0; i < 10; i++)
        string_dict.add(i, ((i % 2) ? "nieparzysta" : "parzysta"));
    string_dict.print();
}
