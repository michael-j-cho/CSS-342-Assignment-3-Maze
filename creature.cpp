//
// Created by Yusuf Pisan on 4/18/18.
//

#include "creature.h"

std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "C(" << Creature.Row << "," << Creature.Col << ")";
  return Out;
}

Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

bool Creature::atExit(const Maze &Maze) const {
  if(this->Row == Maze.getExitRow() && this->Col == Maze.getExitColumn()) {
    return true;
  }
  return false;
}

string Creature::solve(Maze &Maze) {
  //Starting location
  Maze.markAsPath(Row,Col);
  checkDirection(Maze);
  string Path;
  return Path;
}

string Creature::goNorth(Maze &Maze) {
  Maze.markAsPath(Row + 1, Col);
  this->Row++;
  checkDirection(Maze);
  return "X";
}

string Creature::goWest(Maze &Maze) {
  Maze.markAsPath(Row, Col - 1);
  this->Col--;
  checkDirection(Maze);
  return "X";
}

string Creature::goEast(Maze &Maze) {
  Maze.markAsPath(Row, Col + 1);
  this->Col++;
  checkDirection(Maze);
  return "X";
}

string Creature::goSouth(Maze &Maze) {
  Maze.markAsPath(Row - 1, Col);
  this->Row--;
  checkDirection(Maze);
  return "X";
}

void Creature::checkDirection(Maze &Maze) {
  if(Maze.isClear(Row + 1, Col)) {goNorth(Maze);}
  if(Maze.isClear(Row, Col + 1)) {goEast(Maze);}
  if(Maze.isClear(Row - 1, Col)) {goSouth(Maze);}
  if(Maze.isClear(Row, Col - 1)) {goWest(Maze);}
}