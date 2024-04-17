//
// Created by Kubak on 09.04.2024.
//

#include "Bug.h"

Bug::Bug(int id, std::pair<int, int> position, int direction)
{
    this->id = id;
    this->position = position;
    this->direction = Direction(direction-1);
    this->alive = true;
}

bool Bug::isWayBlocked()
{
    switch (direction)
    {
        case NORTH:
            if(position.first == 0)
            {
                return true;
            }
            break;
        case SOUTH:
            if(position.first == 9)
            {
                return true;
            }
            break;
        case WEST:
            if(position.second == 0)
            {
                return true;
            }
            break;
        case EAST:
            if(position.second == 9)
            {
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}