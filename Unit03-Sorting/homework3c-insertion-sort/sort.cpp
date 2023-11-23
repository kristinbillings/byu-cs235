#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const* argv[]) {
    // Write your code here
    string userInput;
    vector<string> lines;


    if(argc > 1) {
        string inputStr = argv[1];
        ifstream ifp(inputStr);
        while(getline(ifp, userInput)) {
            lines.push_back(userInput);
        }
    }
    else {
        while(getline(cin, userInput)) {
            lines.push_back(userInput);
        }
    }


    int n = lines.size();

    for (int i = 1; i < n; i++) {
        string currentItem = lines[i];
        int previous = i - 1;

        while (previous >= 0 && lines[previous] > currentItem) {
            lines[previous + 1] = lines[previous];
            previous = previous - 1;
        }
        lines[previous + 1] = currentItem;
    }



    //prints array
    for(int i = 0; i < n; i++) {
        cout << lines[i] << endl;
    }
    return 0;
}
