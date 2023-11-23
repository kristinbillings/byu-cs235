#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Grid.h"
using namespace std;
//in class example
/*int sum(int n) {
    int s = 0;
    for(int i = 1;i <= n; i++) {
        s += 1;
    }
    return s;
}
//P3: have faith
int sumRec(int n) {
    //base case: P1: need a good base case
    if (n <= 0) {
        return 0;
    }
    //recursive step: P2: have a recursive step that is correct
    //assuming the smaller problem it calls is correct and
    //works towards the base case
    return n + sumRec(n-1); //calls itself
}
*/

vector <string> finalPath;

bool solveMaze(Grid &maze, int h, int w, int d){
    finalPath.push_back(to_string(h) + " " + to_string(w) + " " + to_string(d));

    //base case
    // checks that they haven't left the maze
    if ((h < 0) || (w < 0) || (d < 0) || (h >= maze.height()) || (w >= maze.width()) || (d >= maze.depth())) {
        finalPath.pop_back();
        return false;
    }

    //checks to see if you can go here
    if (maze.at(h,w,d)==0) {
        finalPath.pop_back();
        return false;
    }
    // checks to see if at the end
    if ((h == maze.height()-1) && (w == maze.width()-1) && (d == maze.depth()-1)) {
        maze.at(h,w,d) = 2;
        return true;
    }

    if (maze.at(h,w,d) == 2) {
        finalPath.pop_back();
        return false;
    }

    //sees if you can go to this location
    maze.at(h, w, d) = 2;


    //recursive step
    if (solveMaze(maze, h + 1, w, d) ||
        solveMaze(maze, h - 1, w, d) ||
        solveMaze(maze, h, w + 1, d) ||
        solveMaze(maze, h, w - 1, d) ||
        solveMaze(maze, h, w, d + 1) ||
        solveMaze(maze, h, w, d - 1)) {

        return true;
    }

    finalPath.pop_back();
    return false;
}


int main(int argc, char* argv[]) {
    // Write your code here

    ifstream input(argv[1]);
    ofstream output(argv[2]);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    Grid maze; // allocate a new, blank Grid
    input >> maze; // read from an input stream into a Grid

    //output << "The maze is " << maze.height() << " spaces tall, " << maze.width() << " spaces wide, and " << maze.depth() << " spaces deep" << std::endl; // access the maze's dimensions

    // Prints the solution to the maze
    if (solveMaze(maze, 0, 0, 0 )){
        output << "SOLUTION" << endl;
        for (int i = 0; i < finalPath.size(); i++) {
            output << finalPath[i] << endl;
        }
    }
    else {
        output << "NO SOLUTION" << endl;
    }

    return 0;
}
