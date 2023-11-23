#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char const* argv[]) {
    // Write your code here
    int numLines = 10;
    string fileName = "No file name given";
    string userInput;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            //need to write code to find the number of lines
            numLines = atoi(argv[i]+1);
        }
        else {
            fileName = argv[i]; //the file that should be opened
        }
    }

    if (fileName == "No file name given") {
        int i = 0;
        while (i < numLines) {
            getline(cin, userInput);
            cout << userInput << endl;
            i = i + 1;
        }
    }
    else {
        ifstream input(fileName); //declares fstream variable and connects string to object
        string arg1 = argv[1];
        if (!input) {
            cerr << "ERROR: can't open " << fileName << endl;
            return 1;
        } else {
            int i = 0;
            string nextLine;
            while (getline(input,nextLine) and i < numLines) {
                cout << nextLine << endl;
                i = i + 1;
            }
        }
    }

    //if the file is empty then read it in standard form
    //use two variable string line and an int to keep track of how many lines you have read
    //while int tracker is less then the numlines and you can still get the standard form
    //output the line
    //increase in tracker value

    //else do the exact same thing for non standard form
    // but get input from the input file instead of user input (cin)

    return 0;
}
