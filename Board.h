//
// Created by Kubak on 16.04.2024.
//

#ifndef BUGS_BOARD_CA2_BOARD_H
#define BUGS_BOARD_CA2_BOARD_H

#include <map>
#include <vector>
#include <iostream>
#include "Bug.h"

class Board
{
private:
    std::map<std::pair<int,int>, std::vector<Bug*>> board;
public:
    Board();
    void addBug(std::pair<int,int> pos, Bug *bug);
    void displayAllBugs() const;
    void displayAllBugsHistory() const;
    void findBug(int id) const;
    void tap();
};

#endif //BUGS_BOARD_CA2_BOARD_H