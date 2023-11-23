#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char const* argv[]) {
    string inputStr = argv[1];
    string outputStr = argv[2];

    ifstream ifp(inputStr);//opens the file
    ofstream ofp(outputStr);

    string line;
    string firstName;
    string lastName;
    int points;
    double factor;

    while(getline(ifp, line)){
        //gets the first line from the file
        istringstream ss(line); //this makes it so we can get each variable out of the line, ss is just a variable
        ss >> firstName;
        ss >> lastName;
        ss >> points;
        ss >> factor;

        ofp << lastName << ", " << firstName << ": " << (points * factor) << endl;
    }

    ifp.close(); //closes the file
    ofp.close();

    return 0;
}
