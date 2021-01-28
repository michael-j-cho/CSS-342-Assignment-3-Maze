//
// Created by Yusuf Pisan on 4/18/18.
//

#include "creature.h"
#include <iostream>
using namespace std;

std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "C(" << Creature.Row << "," << Creature.Col << ")";
  return Out;
}

Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

bool Creature::atExit(const Maze &Maze) const {
  return this->Row == Maze.getExitRow() && this->Col == Maze.getExitColumn();
}


string Creature::solve(Maze &Maze) {
  string Path;
  Maze.markAsPath(Row, Col);

  // Base Case
  if(atExit(Maze)){
    return Path;
  }

  if(!atExit(Maze)){
    if(Maze.isClear(Row - 1, Col)) {return goNorth(Maze);}
    if(Maze.isClear(Row, Col + 1)) {return goEast(Maze);}
    if(Maze.isClear(Row + 1, Col)) {return goSouth(Maze);}
    if(Maze.isClear(Row, Col - 1)) {return goWest(Maze);}
    
    if(Maze.hasVisited(Row - 1, Col)) {return goNorth(Maze);}
    if(Maze.hasVisited(Row, Col + 1)) {return goEast(Maze);}
    if(Maze.hasVisited(Row + 1, Col)) {return goSouth(Maze);}
    if(Maze.hasVisited(Row, Col - 1)) {return goWest(Maze);}
  }
  return Path;
}

string Creature::goNorth(Maze &Maze) {
  if(Maze.isClear(Row - 1, Col)) {
    this->Row--;
    Maze.markAsPath(Row, Col);
  } 
  else if(Maze.hasVisited(Row - 1, Col)) {
    Maze.markAsVisited(Row, Col);
    this->Row--;
  }
  return "N" + solve(Maze);
}

string Creature::goWest(Maze &Maze) {
  if(Maze.isClear(Row, Col - 1)) {
    this->Col--;
    Maze.markAsPath(Row, Col);
  } 
  else if (Maze.hasVisited(Row, Col -1)) {
    Maze.markAsVisited(Row, Col);
    this->Col--;
  }
  return "W" + solve(Maze);
}

string Creature::goEast(Maze &Maze) {
  if(Maze.isClear(Row, Col + 1)) {
    this->Col++;
    Maze.markAsPath(Row, Col);
  } 
  else if (Maze.hasVisited(Row, Col + 1)) {
    Maze.markAsVisited(Row, Col);
    this->Col++;
  }
  return "E" + solve(Maze);
}

string Creature::goSouth(Maze &Maze) {
  if(Maze.isClear(Row + 1, Col)) {
    this->Row++;
    Maze.markAsPath(Row, Col);
  } 
  else if(Maze.hasVisited(Row + 1, Col)) {
    Maze.markAsVisited(Row, Col);
    this->Row++;
  }
  return "S" + solve(Maze);
}
