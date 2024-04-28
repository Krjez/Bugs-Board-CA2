//
// Created by Kubak on 17.04.2024.
//

#include <cstdlib>
#include "Crawler.h"

Crawler::Crawler(int id, std::pair<int, int> position, int direction, int size)
: Bug("Crawler", id, position, direction, size){}

void Crawler::move()
{
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