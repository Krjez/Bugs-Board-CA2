//
// Created by Kubak on 28.04.2024.
//

#ifndef BUGS_BOARD_CA2_SCAVENGER_H
#define BUGS_BOARD_CA2_SCAVENGER_H

#include "../Bug.h"

/**
 * Custom Bug - Scavenger
 * Movement - slower than usual bugs, takes specific amount of taps(seconds) to make one move
 * Special ability - can and ONLY eats parts of dead bugs, but it doesn't matter if they are bigger
 */

class Scavenger : public Bug
{
private:
    int moveCooldown;
    int tapToMove;
public:
    Scavenger(int id, std::pair<int, int> position, int direction, int size, int moveCooldown);
    void move();
};


#endif //BUGS_BOARD_CA2_SCAVENGER_H
