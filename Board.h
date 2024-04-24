//
// Created by Kubak on 16.04.2024.
//

#ifndef BUGS_BOARD_CA2_BOARD_H
#define BUGS_BOARD_CA2_BOARD_H

#include <map>
#include <vector>
#include "Bug.h"

class Board
{
private:
    std::map<std::pair<int,int>, std::vector<Bug*>> board;
public:
    Board();
    void tap();
};

#endif //BUGS_BOARD_CA2_BOARD_H