#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const* argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

//    if (start >= end) /*makes start the smaller number*/{
//        int a = start;
//        int b = end;
//
//        start = b;
//        end = a;
//    }

    if (start <= end) /*makes start the smaller number*/{
        for (int i = start; i <= end; i++) {
            if (i % divisor == 0) {
                cout << i << endl;
            }
        }
    }
    else{
        for (int i = start; i >= end; i--) {
            if (i % divisor == 0) {
                cout << i << endl;
            }
        }
    }
    return 0;
}