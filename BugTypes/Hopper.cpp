//
// Created by Kubak on 17.04.2024.
//

#include <cstdlib>
#include <ctime>
#include "Hopper.h"

Hopper::Hopper(int id, std::pair<int, int> position, int direction, int size, int hopLength) : Bug(id, position, direction, size)
{
    this->hopLength = hopLength;
}

void Hopper::move()
{
    srand(time(NULL));
    while(isWayBlocked())
    {
        direction = Direction(rand() % 4);
    }
    switch (direction)
    {
        case NORTH:
            if(position.first - hopLength < 0)
            {
                position.first = 0;
                break;
            }
            else
            {
                position.first -= hopLength;
                break;
            }
        case SOUTH:
            if(position.first + hopLength > 9)
            {
                position.first = 9;
                break;
            }
            else
            {
                position.first += hopLength;
                break;
            }
        case WEST:
            if(position.second - hopLength < 0)
            {
                position.second = 0;
                break;
            }
            else
            {
                position.second -= hopLength;
                break;
            }
        case EAST:
            if(position.second + hopLength > 9)
            {
                position.second = 9;
                break;
            }
            else
            {
                position.first += hopLength;
                break;
            }
    }
    path.push_back(std::pair<int,int>(position));
}