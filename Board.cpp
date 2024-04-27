//
// Created by Kubak on 16.04.2024.
//

#include "Board.h"
#include "BugTypes/Crawler.h"
#include "BugTypes/Hopper.h"

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

/**
 * Board creation and populating with bugs
 */
void Board::initializeBoard()
{
    std::ifstream file("../bugs.txt");
    if(file)
    {
        const char delimiter = ';';
        while(!file.eof())
        {
            std::string type;
            std::string value;
            getline(file,type,delimiter);
            if(type == "C")
            {
                getline(file,value,delimiter);
                int id = stoi(value);
                getline(file,value,delimiter);
                int x = stoi(value);
                getline(file,value,delimiter);
                int y = stoi(value);
                getline(file,value,delimiter);
                int direction = stoi(value);
                //Reads rest of line without delimiter - ends at newline character instead
                getline(file,value);
                int size = stoi(value);
                this->addBug({x,y},new Crawler(id,{x,y},direction,size));
            }
            else if(type == "H")
            {
                getline(file,value,delimiter);
                int id = stoi(value);
                getline(file,value,delimiter);
                int x = stoi(value);
                getline(file,value,delimiter);
                int y = stoi(value);
                getline(file,value,delimiter);
                int direction = stoi(value);
                getline(file,value,delimiter);
                int size = stoi(value);
                //Reads rest of line without delimiter - ends at newline character instead
                getline(file,value);
                int hopLength = stoi(value);
                this->addBug({x,y},new Hopper(id,{x,y},direction,size,hopLength));
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Error when loading in the file." << std::endl;
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

void Board::writeAllBugsHistory() const
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
        if(bug->getAlive())
        {
            bug->move();
        }
    }
}