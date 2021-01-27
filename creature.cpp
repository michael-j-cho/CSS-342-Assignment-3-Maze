//
// Created by Yusuf Pisan on 4/18/18.
//

#include "creature.h"
#include <iostream>

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
  // Maze.markAsPath(Row,Col);
  checkDirection(Maze);
  string Path;
  return Path;
}

string Creature::goNorth(Maze &Maze) {
  if(Maze.isClear(Row - 1, Col)) {
    Maze.markAsPath(Row, Col);
    this->Row--;
    std::cout << "Up" << endl;
  } 
  else if(Maze.hasVisited(Row - 1, Col)) {
    Maze.markAsVisited(Row, Col);
    this->Row--;
    std::cout << "Up" << endl;
  }
  checkDirection(Maze);
  return "X";
}

string Creature::goWest(Maze &Maze) {
  if(Maze.isClear(Row, Col - 1)) {
    Maze.markAsPath(Row, Col);
    this->Col--;
    std::cout << "Left" << endl;
  } 
  else if (Maze.hasVisited(Row, Col -1)) {
    Maze.markAsVisited(Row, Col);
    this->Col--;
    std::cout << "Left" << endl;
  }
  checkDirection(Maze);
  return "X";
}

string Creature::goEast(Maze &Maze) {
  if(Maze.isClear(Row, Col + 1)) {
    Maze.markAsPath(Row, Col);
    this->Col++;
    std::cout << "Right" << endl;
  } 
  else if (Maze.hasVisited(Row, Col + 1)) {
    Maze.markAsVisited(Row, Col);
    this->Col++;
    std::cout << "Right" << endl;
  }
  checkDirection(Maze);
  return "X";
}

string Creature::goSouth(Maze &Maze) {
  if(Maze.isClear(Row + 1, Col)) {
    Maze.markAsPath(Row, Col);
    this->Col--;
    std::cout << "Down" << endl;
  } 
  else if(Maze.hasVisited(Row + 1, Col)) {
    Maze.markAsVisited(Row, Col);
    this->Col--;
    std::cout << "Down" << endl;
  }
  checkDirection(Maze);
  return "X";
}

void Creature::checkDirection(Maze &Maze) {
  std::cout << Maze << endl;
  std::cout << this->Row << ":" << this->Col << endl;
  if(Maze.isClear(Row, Col - 1)) {goWest(Maze);}
  if(Maze.isClear(Row, Col + 1)) {goEast(Maze);}
  if(Maze.isClear(Row + 1, Col)) {goSouth(Maze);}
  if(Maze.isClear(Row - 1, Col)) {goNorth(Maze);}

  if(Maze.hasVisited(Row, Col - 1)) {goWest(Maze);}
  if(Maze.hasVisited(Row, Col + 1)) {goEast(Maze);}
  if(Maze.hasVisited(Row + 1, Col)) {goSouth(Maze);}
  if(Maze.hasVisited(Row - 1, Col)) {goNorth(Maze);}

}