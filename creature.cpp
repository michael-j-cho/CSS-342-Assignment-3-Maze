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
