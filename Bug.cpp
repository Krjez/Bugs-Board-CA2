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
