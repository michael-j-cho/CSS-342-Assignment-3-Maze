#include <iostream>

#include "creature.h"
#include "maze.h"

void test() {
  Maze M("maze.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
}

void test2() {
  Maze M("maze2.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
}

void test3() {
  Maze M("maze3.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
}

void test4() {
  Maze M("maze4.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
}

int main() {
  test();
  test2();
  test3();
  test4();
  cout << "Done!" << std::endl;
  return 0;
}