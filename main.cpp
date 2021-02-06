/** Michael Cho 2/5/21
CSS342

This is the main driver file. It is running four
different test for four different mazes. */

#include "creature.h"
#include "maze.h"
#include <cassert>
#include <iostream>

/** Test. Creates a maze with maze.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks to see if the creature is
at the exit after the maze has been solved. */
void test() {
  Maze M("maze.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
  assert(C.atExit(M));
}

/** Test. Creates a maze with maze.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks to see if the creature is
at the exit after the maze has been solved. */
void test2() {
  Maze M("maze2.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
  assert(C.atExit(M));
}

/** Test. Creates a maze with maze.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks to see if the creature is
at the exit after the maze has been solved. */
void test3() {
  Maze M("maze3.txt");
  // cout << M << endl;
  Creature C(4, 4);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
  assert(C.atExit(M));
}

/** Test. Creates a maze with maze.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks to see if the creature is
at the exit after the maze has been solved. */
void test4() {
  Maze M("maze4.txt");
  // cout << M << endl;
  Creature C(5, 28);
  // cerr << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  cout << M << endl;
  assert(C.atExit(M));
}

/** Main function that runs tests 1-4. */
int main() {
  test();
  test2();
  test3();
  test4();
  cout << "Done!" << std::endl;
  return 0;
}