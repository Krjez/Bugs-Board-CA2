//
// Created by Kubak on 16.04.2024.
//

#ifndef BUGS_BOARD_CA2_BOARD_H
#define BUGS_BOARD_CA2_BOARD_H

#include "vector"
#include "Bug.h"

class Board
{
private:
    std::vector<std::pair<int,int>> cells;
    std::vector<Bug*> bugs;
public:
    Board(std::vector<std::pair<int,int>> cells, std::vector<Bug*> bugs);
    void tap();
};


#endif //BUGS_BOARD_CA2_BOARD_H
