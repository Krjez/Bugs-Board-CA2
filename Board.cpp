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
    bugs.push_back(bug);
}

void Board::displayAllBugs() const
{
    for (const auto &bug : bugs)
    {
        std::cout << *bug << std::endl;
    }
}

void Board::displayAllBugsHistory() const
{
    for (const auto &bug : bugs)
    {
        std::cout << bug->getHistory() << std::endl;
    }
}

void Board::findBug(int id) const
{
    for (const auto &bug : bugs)
    {
        if(bug->getId() == id)
        {
            std::cout << *bug << std::endl;
            return;
        }
    }
    std::cout << "Bug " << id << " not found." << std::endl;
}

void Board::tap()
{
    for (const auto &bug : bugs)
    {
        // TODO if(bug.alive
        bug->move();
    }
}