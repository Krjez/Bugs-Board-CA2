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

int Bug::getId() const
{
    return id;
}

std::string Bug::getType() const
{
    return type;
}

std::pair<int, int> Bug::getPosition() const
{
    return position;
}

int Bug::getSize() const
{
    return size;
}


bool Bug::getAlive() const
{
    return alive;
}

std::string Bug::getHistory() const
{
    std::string history = std::to_string(id) + " " + type + " Path: ";
    auto iter = path.cbegin();
    while(iter != path.cend())
    {
        history += "(" + std::to_string(iter->first) + ",";
        history += std::to_string(iter->second) + "),";
        iter++;
    }
    history += alive ? " Alive!" : " Eaten by " + std::to_string(diedToId);
    return history;
}

bool Bug::isWayBlocked()
{
    switch (direction)
    {
        case NORTH:
            if(position.second == 0)
            {
                return true;
            }
            break;
        case SOUTH:
            if(position.second == 9)
            {
                return true;
            }
            break;
        case WEST:
            if(position.first == 0)
            {
                return true;
            }
            break;
        case EAST:
            if(position.first == 9)
            {
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

void Bug::eat(Bug* &bug)
{
    size += bug->getSize();
    bug->diedToId = id;
    bug->alive = false;
}

void Bug::eatDead(Bug* bug)
{
    size += bug->getSize();
    bug->size = 0;
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