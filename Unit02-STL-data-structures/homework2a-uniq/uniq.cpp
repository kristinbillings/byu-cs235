#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char const* argv[]) {
    // Write your code

    string word;

    vector<string> finalVector;


    if (argc == 1) {
        while (getline(cin, word)) {
            bool alreadyExists = false;
            for (int i = 0; i < finalVector.size(); i++) {
                if (finalVector[i] == word) {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists) {
                finalVector.push_back(word);
            }
        }
    } else {
        string inputStr = argv[1];
        ifstream ifp(inputStr.c_str()); //converts string to char
        while (getline(ifp, word)) {
            bool alreadyExists = false;
            for (int i = 0; i < finalVector.size(); i++) {
                if (finalVector[i] == word) {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists) {
                finalVector.push_back(word);
            }
        }
    }


    for (int i = 0; i < finalVector.size(); i++) {
        cout << finalVector[i] << endl;
    }

    //his code inclass
    /*
     * vector<string>::iterator itr;
     * cout << "Elements of the vector are: ";
     * for (itr = u.begin(); itr != u.end(), itr++) {
     *      cout << *itr << " ";               //the star before give you the object, not just the location
     * }
     * cout << endl;
     */
    return 0;
}
