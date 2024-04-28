//
// Created by Kubak on 28.04.2024.
//

#include <cstdlib>
#include "Scavenger.h"

Scavenger::Scavenger(int id, std::pair<int, int> position, int direction, int size, int moveCooldown)
: Bug("Scavenger", id, position, direction, size)
{
    this->moveCooldown = moveCooldown;
    this->tapToMove = moveCooldown;
}

void Scavenger::move()
{
    if(tapToMove != 0)
    {
        tapToMove -= 1;
    }
    else
    {
        tapToMove = moveCooldown;
        while(isWayBlocked())
        {
            direction = Direction(rand() % 4);
        }
        switch (direction)
        {
            case NORTH:
                position.second -= 1;
                break;
            case SOUTH:
                position.second += 1;
                break;
            case WEST:
                position.first -= 1;
                break;
            case EAST:
                position.first += 1;
                break;
        }
        path.push_back(std::pair<int,int>(position));
    }
}