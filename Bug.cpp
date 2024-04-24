//
// Created by Kubak on 09.04.2024.
//

#include "Bug.h"

Bug::Bug(std::string type, int id, std::pair<int, int> position, int direction, int size)
{
    this->type = type;
    this->id = id;
    this->position = position;
    this->direction = Direction(direction-1);
    this->size = size;
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

std::string Bug::toString() const
{
    return "Id: " + std::to_string(id) +
    ", Type: " + type +
    ", Position: (" + std::to_string(position.first) + "," + std::to_string(position.second) + ")" +
    ", Size: " + std::to_string(size) +
    ", Direction: " + std::to_string(direction) +
    ", Status: " + (alive ? "Alive" : "Dead");
}

std::ostream &operator<<(std::ostream &out, const Bug &bug)
{
    return out << bug.toString();
}