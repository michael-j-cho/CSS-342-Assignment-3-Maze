/** Michael Cho 2/5/21
CSS342

Creature class header file */


#pragma once
#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
  /** Overloaded << operator displays location of creature.
  Precondition: None.
  Postcondition: Displays location of creature on screen. */
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;
  string Path;

public:
  /** Constructor: Creates a creature and initializes the Row and
  Col to Row and Col paramaters.
  Precondition: None.
  Postcondition: Creates creature at location (Row, Col). */
  Creature(int Row, int Col);

  /** Checks to see if the creature is at the exit.
  Precondition: None.
  Postcondition: If creature is at exit, return true. */
  bool atExit(const Maze &Maze) const;

  /** Recursive function solve. Base case is when creature is at exit.
  First block of if/else statements move the creature while there are 
  open paths available. If there are no open paths available, creature
  backtracks with the second block of if/else statements. In both blocks
  of if/else statements, there is a recursive call to solve(Maze).
  Precondition: None
  Postcondition: Recursively moves creature in different directions until
  it is at exit. Returns the Path string directions for the solution. */
  string solve(Maze* Maze);

  /** If path is clear, moves the creature North and marks path with 
  '*'. Else, if path is not clear and marked with '*', marks '+' in 
  current spot and moves North over a previously visited spot '*'.
  Precondition: Row - 1 must be ' ' or '*'.
  Postcondition: Marks location and moves creature Row - 1. 
  Only returns 'N' if spot is clear and hasn't been visited.*/
  string goNorth(Maze* Maze);

  /** If path is clear, moves the creature West and marks path with 
  '*'. Else, if path is not clear and marked with '*', marks '+' in 
  current spot and moves West over a previously visited spot '*'.
  Precondition: Col - 1 must be ' ' or '*'.
  Postcondition: Marks location and moves creature Col - 1. 
  Only returns 'W' if spot is clear and hasn't been visited.*/
  string goSouth(Maze* Maze);

  /** If path is clear, moves the creature East and marks path with 
  '*'. Else, if path is not clear and marked with '*', marks '+' in 
  current spot and moves East over a previously visited spot '*'.
  Precondition: Col + 1 must be ' ' or '*'.
  Postcondition: Marks location and moves creature Col + 1.
  Only returns 'E' if spot is clear and hasn't been visited. */
  string goEast(Maze* Maze);

  /** If path is clear, moves the creature South and marks path with 
  '*'. Else, if path is not clear and marked with '*', marks '+' in 
  current spot and moves South over a previously visited spot '*'.
  Precondition: Row + 1 must be ' ' or '*'.
  Postcondition: Marks location and moves creature Row + 1.
  Only returns 'S' if spot is clear and hasn't been visited. */
  string goWest(Maze* Maze);

  /** Checks to see if adjacent spaces are clear.
  Precondition: None
  Postcondition: If space is clear in any direction, return true. */ 
  bool canMove(Maze* Maze) const;
};

#endif //ASS3_CREATURE_H
