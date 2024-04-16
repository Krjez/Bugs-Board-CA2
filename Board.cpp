//
// Created by Kubak on 16.04.2024.
//

#include "Board.h"

Board::Board(std::vector<std::pair<int, int>> cells, std::vector<Bug*> bugs)
{
    this->cells = cells;
    this->bugs = bugs;
}

void Board::tap()
{
    for (Bug b : bugs)
    {
        std::move(b);
    }
}