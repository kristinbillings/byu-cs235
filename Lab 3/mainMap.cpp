//
// Created by Riley on 10/9/2023.
//
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[]) {
    // Sets
    set<string> strset;
    strset.insert("bug");
    strset.insert("horse");
    strset.insert("horse");
    set<string>::iterator findit;
    findit = strset.find("horse");
    cout << "Found horse " << *findit << endl;
    for (set<string>::iterator it = strset.begin(); it != strset.end(); ++it)
        cout << ' ' << *it;
    cout << endl;

    vector<string> tokens;
    set<string> unique;
    string next_line;  // Each data line
    string filename = argv[1];
    ifstream in(argv[1]);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for (auto &c: token) { // Remove Punctuation
                if (isalpha(c)) {
                    nopunct += c;
                }
            }
            tokens.push_back(nopunct);
            unique.insert(nopunct);
            // cout << token<<endl;
        }
    }
    cout << "Number of words " << tokens.size() << endl;
    cout << "Number of unique words " << unique.size() << endl;
    ofstream setfile(filename + "_set.txt");
    for (set<string>::iterator it = unique.begin(); it != unique.end(); ++it) {
        cout << ' ' << *it;
        setfile << " " << *it;
    }
    cout << endl;





    return 0;
}