//
// Michael Cho 2/5/21
// CSS342
// 
// This is the main driver file. It is running four 
// different test of four different mazes.
//

#include <iostream>
#include <cassert>
#include "creature.h"
#include "maze.h"

void test() {
  Maze M("maze.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
  assert(C.atExit(M));
}

void test2() {
  Maze M("maze2.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
  assert(C.atExit(M));
}

void test3() {
  Maze M("maze3.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
  assert(C.atExit(M));
}

void test4() {
  Maze M("maze4.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
  assert(C.atExit(M));
}

int main() {
  test();
  test2();
  test3();
  test4();
  cout << "Done!" << std::endl;
  return 0;
}