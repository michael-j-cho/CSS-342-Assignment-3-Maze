//
// Michael Cho 2/5/21
// CSS342
// 
// The creature class creates an object that navigates through the
// maze object. This class has an overloaded << operator that prints
// the location of the creature. There is also an atExit function
// that returns a boolean is the creature is at the exit. The solve
// function is a recursive function that initiates the movement of
// the creature throughout the maze. It will first move towards empty
// spaces, then if there are no clear spaces left and it is not at the
// exit, it will backtrack to previously visited spaces. There are 
// also functions for moving North, East, South, and West, as well
// as a function for checking if the creature can move to an empty space.

#include "creature.h"
#include <iostream>
using namespace std;

/** Overloaded << operator displays location of creature.
Precondition: None.
Postcondition: Displays location of creature on screen. */
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "C(" << Creature.Row << "," << Creature.Col << ")";
  return Out;
}

/** Constructor: Creates a creature and initializes the Row and
Col to Row and Col paramaters.
Precondition: None.
Postcondition: Creates creature at location (Row, Col). */
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

/** Checks to see if the creature is at the exit.
Precondition: None.
Postcondition: If creature is at exit, return true. */
bool Creature::atExit(const Maze &Maze) const {
  return this->Row == Maze.getExitRow() && this->Col == Maze.getExitColumn();
}

/** Recursive function solve. Base case is when creature is at exit.
First block of if/else statements move the creature while there are 
open paths available. If there are no open paths available, creature
backtracks with the second block of if/else statements. In both blocks
of if/else statements, there is a recursive call to solve(Maze).
Precondition: None
Postcondition: Recursively moves creature in different directions until
it is at exit. Returns the Path string directions for the solution. */
string Creature::solve(Maze* Maze) {
  Maze->markAsPath(Row, Col);
  if (atExit(*Maze)) {
    return Path;
  }

  if (!atExit(*Maze) && canMove(Maze)) {
    if (Maze->isClear(Row - 1, Col)) {
      Path.append(goNorth(Maze));
    } else if (Maze->isClear(Row, Col + 1)) {
      Path.append(goEast(Maze));
    } else if (Maze->isClear(Row + 1, Col)) {
      Path.append(goSouth(Maze));
    } else if (Maze->isClear(Row, Col - 1)) {
      Path.append(goWest(Maze));
    }
    solve(Maze);
  }

  if (!atExit(*Maze) && !canMove(Maze)) {
    Path.pop_back();
    if (Maze->hasVisited(Row - 1, Col)) {
      goNorth(Maze);
    } else if (Maze->hasVisited(Row, Col + 1)) {
      goEast(Maze);
    } else if (Maze->hasVisited(Row + 1, Col)) {
      goSouth(Maze);
    } else if (Maze->hasVisited(Row, Col - 1)) {
      goWest(Maze);
    }
    solve(Maze);
  }
  return Path;
}

/** If path is clear, moves the creature North and marks path with 
'*'. Else, if path is not clear and marked with '*', marks '+' in 
current spot and moves North over a previously visited spot '*'.
Precondition: Row - 1 must be ' ' or '*'.
Postcondition: Marks location and moves creature Row - 1. 
Only returns 'N' if spot is clear and hasn't been visited.*/
string Creature::goNorth(Maze* Maze) {
  if (Maze->isClear(Row - 1, Col)) {
    this->Row--;
    Maze->markAsPath(Row, Col);
  } else if (Maze->hasVisited(Row - 1, Col)) {
    Maze->markAsVisited(Row, Col);
    this->Row--;
    return "";
  }
  return "N";
}

/** If path is clear, moves the creature West and marks path with 
'*'. Else, if path is not clear and marked with '*', marks '+' in 
current spot and moves West over a previously visited spot '*'.
Precondition: Col - 1 must be ' ' or '*'.
Postcondition: Marks location and moves creature Col - 1. 
Only returns 'W' if spot is clear and hasn't been visited.*/
string Creature::goWest(Maze* Maze) {
  if (Maze->isClear(Row, Col - 1)) {
    this->Col--;
    Maze->markAsPath(Row, Col);
  } else if (Maze->hasVisited(Row, Col - 1)) {
    Maze->markAsVisited(Row, Col);
    this->Col--;
    return "";
  }
  return "W";
}

/** If path is clear, moves the creature East and marks path with 
'*'. Else, if path is not clear and marked with '*', marks '+' in 
current spot and moves East over a previously visited spot '*'.
Precondition: Col + 1 must be ' ' or '*'.
Postcondition: Marks location and moves creature Col + 1.
Only returns 'E' if spot is clear and hasn't been visited. */
string Creature::goEast(Maze* Maze) {
  if (Maze->isClear(Row, Col + 1)) {
    this->Col++;
    Maze->markAsPath(Row, Col);
  } else if (Maze->hasVisited(Row, Col + 1)) {
    Maze->markAsVisited(Row, Col);
    this->Col++;
    return "";
  }
  return "E";
}

/** If path is clear, moves the creature South and marks path with 
'*'. Else, if path is not clear and marked with '*', marks '+' in 
current spot and moves South over a previously visited spot '*'.
Precondition: Row + 1 must be ' ' or '*'.
Postcondition: Marks location and moves creature Row + 1.
Only returns 'S' if spot is clear and hasn't been visited. */
string Creature::goSouth(Maze* Maze) {
  if (Maze->isClear(Row + 1, Col)) {
    this->Row++;
    Maze->markAsPath(Row, Col);
  } else if (Maze->hasVisited(Row + 1, Col)) {
    Maze->markAsVisited(Row, Col);
    this->Row++;
    return "";
  }
  return "S";
}

/** Checks to see if adjacent spaces are clear.
Precondition: None
Postcondition: If space is clear in any direction, return true. */
bool Creature::canMove(Maze* Maze) const {
  if (Maze->isClear(Row - 1, Col)) {
    return true;
  }
  if (Maze->isClear(Row, Col + 1)) {
    return true;
  }
  if (Maze->isClear(Row + 1, Col)) {
    return true;
  }
  if (Maze->isClear(Row, Col - 1)) {
    return true;
  }
  return false;
}
