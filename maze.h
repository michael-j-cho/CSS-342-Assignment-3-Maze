/** Michael Cho 2/5/21
CSS342

Maze class header file */


#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
  /** Overloaded << operator displays current state of the maze
  with char pathways marked.
  Precondition: Maze must be instantiated.
  Postcondition: Prints the maze on the screen. */
  friend ostream &operator<<(ostream &Out, const Maze &Maze);

private:
  const static int MAX_SIZE = 100;
  char Field[MAX_SIZE][MAX_SIZE];
  int Width, Height;
  int ExitRow, ExitColumn;

public:
  /** Maze constructor. Take the name of the txt file as a paramater.
  Precondition: Text file with appropriate maze must exist.
  Postcondition: Constructs the maze with the blueprint in txt file. */
  explicit Maze(const string &FileName);

  /** Checks a if a particular location is an empty space ' '.
  Precondition: Must be within the width and height of the maze.
  Postcondition: Returns true is space is empty. */
  bool isClear(int Row, int Col) const;

  /** Checks a if a particular location has been visited by '*' marker.
  Precondition: Must be within the width and height of the maze.
  Postcondition: Returns true is space is marked with '*' */
  bool hasVisited(int Row, int Col) const;

  /** Marks a particular location in the field of the maze with '*'.
  Marks unvisited empty spots.
  Precondition: Must be within the width and height of the maze.
  Postcondition: Changes maze Field (Row, Col) char into '*'. */
  void markAsPath(int Row, int Col);

  /** Marks a particular location in the field of the maze with '+'.
  For previously visited locations.
  Precondition: Must be within the width and height of the maze.
  Postcondition: Changes maze Field (Row, Col) char into '+'. */
  void markAsVisited(int Row, int Col);

  /** Returns the set exit row of the maze from the maze text file.
  Precondition: Maze must be instantiated.
  Postcondition: Returns an integer row location. */
  int getExitRow() const;

  /** Returns the set exit column of the maze from the maze text file.
  Precondition: Maze must be instantiated.
  Postcondition: Returns an integer column location. */
  int getExitColumn() const;

};

#endif //ASS3_MAZE_H
