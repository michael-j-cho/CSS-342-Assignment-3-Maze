#include <iostream>

#include "creature.h"
#include "maze.h"


void test() {
    Maze M("maze.txt");
    // cout << M << endl;
    Creature C(4, 4);
    // cerr << C << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}
int main() {
    test();
    cout << "Done!" << std::endl;
    return 0;
}