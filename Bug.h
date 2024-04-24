//
// Created by Kubak on 09.04.2024.
//

#include <utility>
#include <list>
#include <iostream>

#ifndef BUGS_BOARD_CA2_BUG_H
#define BUGS_BOARD_CA2_BUG_H

class Bug
{
protected:
    std::string type;
    int id;
    std::pair<int, int> position;
    enum Direction{NORTH, SOUTH, WEST, EAST} direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;
public:
    Bug(std::string type, int id, std::pair<int, int> position, int direction, int size);
    virtual void move()=0;
    bool isWayBlocked();
    virtual std::string toString() const;
    friend std::ostream &operator<<(std::ostream &out, const Bug &bug);
};

#endif //BUGS_BOARD_CA2_BUG_H