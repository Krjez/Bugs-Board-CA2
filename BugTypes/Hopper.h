//
// Created by Kubak on 17.04.2024.
//

#ifndef BUGS_BOARD_CA2_HOPPER_H
#define BUGS_BOARD_CA2_HOPPER_H

#include "../Bug.h"

class Hopper : public Bug
{
private:
    int hopLength;
public:
    Hopper(int id, std::pair<int, int> position, int direction, int size, int hopLength);
    void move();
};


#endif //BUGS_BOARD_CA2_HOPPER_H
