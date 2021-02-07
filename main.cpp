/** Michael Cho 2/5/21
CSS342

This is the main driver file. It is running five
different test for five different mazes. */

#include "creature.h"
#include "maze.h"
#include <cassert>
#include <iostream>
#include <fstream>

/** Test. Creates a maze with maze.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks creature's start location, verifies
path string, and checks when the creature is at exit. */

/** To make cleaner code, I made a maze solutions text file
with the solution paths that have been visually checked 
for each maze. Then I created a function in this driver
file to set each of these strings below to the path
solutions. That way I don't have long strings in this file */
string MazeSol, Maze1Sol, Maze2Sol, Maze3Sol, Maze4Sol;

/** This function takes in the maze solution text file
and sets each of the strings above with the path solutions */
void solutionToString(const string &FileName) {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  getline(InFile, MazeSol);
  getline(InFile, Maze1Sol);
  getline(InFile, Maze2Sol);
  getline(InFile, Maze3Sol);
  getline(InFile, Maze4Sol);
}

/** Test. Creates a maze with maze1.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks creature's start location, verifies
path string, and checks when the creature is at exit. */
void test() {
  // Initializes maze with text file.
  Maze M("maze.txt");
  // Creates creature at specitic location, checks location,
  // then prints the location.
  Creature C(4, 4);
  assert(C.getRow() == 4 && C.getCol() == 4);
  cout << C << endl;
  // Solves the maze, checks the path string solution, and
  // verifies that the creature is at the exit.
  cout << "Path: " << C.solve(&M) << endl;
  assert(C.solve(&M) == MazeSol);
  cout << M << endl;
  assert(C.atExit(M));
}

/** Test. Creates a maze with maze1.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks creature's start location, verifies
path string, and checks when the creature is at exit. */
void test2() {
  Maze M("maze1.txt");
  Creature C(4, 4);
  assert(C.getRow() == 4 && C.getCol() == 4);
  cout << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  assert(C.solve(&M) == Maze1Sol);
  cout << M << endl;
  assert(C.atExit(M));
}

/** Test. Creates a maze with maze2.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks creature's start location, verifies
path string, and checks when the creature is at exit. */
void test3() {
  Maze M("maze2.txt");
  Creature C(4, 4);
  assert(C.getRow() == 4 && C.getCol() == 4);
  cout << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  assert(C.solve(&M) == Maze2Sol);
  cout << M << endl;
  assert(C.atExit(M));
}

/** Test. Creates a maze with maze3.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks creature's start location, verifies
path string, and checks when the creature is at exit. */
void test4() {
  Maze M("maze3.txt");
  Creature C(4, 4);
  assert(C.getRow() == 4 && C.getCol() == 4);
  cout << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  assert(C.solve(&M) == Maze3Sol);
  cout << M << endl;
  assert(C.atExit(M));
}

/** Test. Creates a maze with maze4.txt and a creature
in a specific location. Then, solves the maze.
Assertion test checks creature's start location, verifies
path string, and checks when the creature is at exit. */
void test5() {
  Maze M("maze4.txt");
  Creature C(5, 28);
  assert(C.getRow() == 5 && C.getCol() == 28);
  cout << C << endl;
  cout << "Path: " << C.solve(&M) << endl;
  assert(C.solve(&M) == Maze4Sol);
  cout << M << endl;
  assert(C.atExit(M));
}

/** Main function that runs tests 1-5. */
int main() {
  solutionToString("MazeSolutions.txt");
  test();
  test2();
  test3();
  test4();
  test5();
  cout << "Done!" << std::endl;
  return 0;
}