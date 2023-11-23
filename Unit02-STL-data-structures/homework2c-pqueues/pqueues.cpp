#include <iostream>
#include <sstream>
#include <string>
#include <queue>

#include "input.h"
using namespace std;

int main(int argc, char const* argv[]) {
    string name;
    string function;
    priority_queue<string> people;

    while (input("What do you want to do? ", function)) {
        if (function == "add") {
            string priority;
            input("Name: ", name);

            input("Priority: ", priority);

            string newP;
            int priority1 = stoi(priority);
            if (priority1 < 10) {
                newP = "0" + to_string(priority1);
            }
            else {
                newP = to_string(priority1);
            }

            string toAdd = newP + " - " + name;

            people.push(toAdd);
        }
        else if (function == "take") {
            if (people.empty()) {
                cout << "There are no more people in line" << endl;
            }
            else {
                cout << people.top() << endl;
                people.pop();
            }
        }
        else {
            cout << function << "isn't a valid operation" << endl;
        }
    }

    return 0;
}
