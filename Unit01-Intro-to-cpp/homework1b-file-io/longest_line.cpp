#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char const* argv[]) {
    string inputStr = argv[1];

    ifstream ifp(inputStr);//opens the file

    string line;
     //this makes it so we can get each variable out of the line, ss is just a variable

    //string oneWord;
    //cout << inputStr << endl;
    //ss >> oneWord;
    string longestLine;
    int highestCounter = 0;
    string mostLongest;

    while(getline(ifp, longestLine)) {
        int counter = 0;
        string lineNow = longestLine;
        istringstream ss(longestLine);
        while (ss >> inputStr) {
            counter++;
        }
        if (counter > highestCounter) {
            highestCounter = counter;
            mostLongest = lineNow;
        }
    }
    cout << mostLongest << endl;
    ifp.close();
    return 0;
}
