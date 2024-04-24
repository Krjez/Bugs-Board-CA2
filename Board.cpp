//
// Created by Kubak on 16.04.2024.
//

#include "Board.h"

Board::Board()
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            board.insert({{x,y},std::vector<Bug*>()});
        }
    }
}

void Board::addBug(std::pair<int,int> pos, Bug *bug)
{
    board.find(pos)->second.push_back(bug);
}

void Board::displayAllBugs()
{
    for (const auto &cell : board)
    {
        for (const auto &bug: cell.second)
        {
            std::cout << bug << std::endl;
        }
    }
}

void Board::tap()
{
    for (const auto &cell : board)
    {
        for (const auto &bug: cell.second)
        {
            bug->move();
        }
    }
}