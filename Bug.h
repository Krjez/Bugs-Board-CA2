//
// Created by Kubak on 09.04.2024.
//

#include <utility>
#include <list>

#ifndef BUGS_BOARD_CA2_BUG_H
#define BUGS_BOARD_CA2_BUG_H


class Bug
{
protected:
    int id;
    std::pair<int, int> position;
    int direction;//TODO remake
    bool alive;
    std::list<std::pair<int,int>> path;
public:
    Bug(int id, std::pair<int, int> position, int direction);
    virtual void move()=0;
    virtual bool isWayBlocked();
};


#endif //BUGS_BOARD_CA2_BUG_H
