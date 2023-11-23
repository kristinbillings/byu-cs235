#include <iostream>
#include <string>
using namespace std;

void sort(std::string& a, std::string& b, std::string& c) {
    // implement sort here
    string i; //placeholder

    if (a > b and a > c) {
        i = a;
        a = c;

        c = i;
    }
    if (b > a and b > c) {
        i = b;
        b = c;

        c = i;
    }
    if (a > b) {
        i = a;
        a = b;

        b = i;
    }

}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
