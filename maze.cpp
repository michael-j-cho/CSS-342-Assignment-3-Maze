/** Michael Cho 2/5/21
CSS342

This maze class is an object that creates a maze with an input stream
from a premade text file. The class includes an overloaded << operator
that prints the maze to the screen. getExitRow and getExitColumn return
the predetermined row and column of the exit. isClear checks for clear
spots within the maze. hasVisited checks if a location has been visited
and marked with a '*'. Finally, the maze can mark pathways that the
creature takes with '*'s and '+'. */

#include "maze.h"
#include <fstream>
#include <iostream>

using namespace std;

/** Overloaded << operator displays current state of the maze
with char pathways marked.
Precondition: None.
Postcondition: Prints the maze on the screen. */
ostream &operator<<(ostream &Out, const Maze &Maze) {
  for (int Row = 0; Row < Maze.Height; ++Row) {
    for (int Col = 0; Col < Maze.Width; ++Col) {
      Out << Maze.Field[Row][Col];
    }
    Out << endl;
  }
  Out << endl;
  return Out;
}

/** Maze constructor. Take the name of the txt file as a paramater.
Precondition: Text file with appropriate maze must exist.
Postcondition: Constructs the maze with the blueprint in txt file. */
Maze::Maze(const string &FileName) {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  // First two numbers in text file are width and height of maze.
  InFile >> Width >> Height;
  // Next two numbers are the exit row and column.
  InFile >> ExitRow >> ExitColumn;
  string Str;
  getline(InFile, Str);
  for (int Row = 0; Row < Height; ++Row) {
    for (int Col = 0; Col < Width; ++Col) {
      InFile.get(Field[Row][Col]);
    }
    getline(InFile, Str);
  }
}

/** Returns the set exit row of the maze from the maze text file.
Precondition: None.
Postcondition: Returns an integer row location. */
int Maze::getExitRow() const { return ExitRow; }

/** Returns the set exit column of the maze from the maze text file.
Precondition: None.
Postcondition: Returns an integer column location. */
int Maze::getExitColumn() const { return ExitColumn; }

/** Checks a if a particular location is an empty space ' '.
Precondition: Must be within the width and height of the maze.
Postcondition: Returns true is space is empty. */
bool Maze::isClear(int Row, int Col) const { return Field[Row][Col] == ' '; }

/** Checks a if a particular location has been visited by '*' marker.
Precondition: Must be within the width and height of the maze.
Postcondition: Returns true is space is marked with '*' */
bool Maze::hasVisited(int Row, int Col) const { return Field[Row][Col] == '*'; }

/** Marks a particular location in the field of the maze with '*'.
Marks unvisited empty spots.
Precondition: Must be within the width and height of the maze.
Postcondition: Changes maze Field (Row, Col) char into '*'. */
void Maze::markAsPath(int Row, int Col) { Field[Row][Col] = '*'; }

/** Marks a particular location in the field of the maze with '+'.
For previously visited locations.
Precondition: Must be within the width and height of the maze.
Postcondition: Changes maze Field (Row, Col) char into '+'. */
void Maze::markAsVisited(int Row, int Col) { Field[Row][Col] = '+'; }
