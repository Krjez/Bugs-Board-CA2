//
// Created by Kubak on 17.04.2024.
//

#include <cstdlib>
#include <ctime>
#include "Crawler.h"

Crawler::Crawler(int id, std::pair<int, int> position, int direction, int size) : Bug(id, position, direction, size){}

void Crawler::move()
{
    srand(time(NULL));
    while(isWayBlocked())
    {
        direction = Direction(rand() % 4);
    }
    switch (direction)
    {
        case NORTH:
            position.first -= 1;
            break;
        case SOUTH:
            position.first += 1;
            break;
        case WEST:
            position.second -= 1;
            break;
        case EAST:
            position.second += 1;
            break;
    }
    path.push_back(std::pair<int,int>(position));
}