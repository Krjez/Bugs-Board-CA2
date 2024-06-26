//
// Created by Kubak on 16.04.2024.
//

#include "Board.h"
#include "BugTypes/Crawler.h"
#include "BugTypes/Hopper.h"
#include "BugTypes/Scavenger.h"

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
                getline(file,value);
                int hopLength = stoi(value);
                this->addBug({x,y},new Hopper(id,{x,y},direction,size,hopLength));
            }
            else if(type == "S")
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
                getline(file,value);
                int moveCooldown = stoi(value);
                this->addBug({x,y},new Scavenger(id,{x,y},direction,size,moveCooldown));
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

void Board::displayAllCells() const
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            std::pair<int, int> cell = {x, y};
            std::cout << "(" << x << "," << y << "):";

            auto iter = board.find(cell);
            if (iter == board.end() || iter->second.empty())
            {
                std::cout << " empty" << std::endl;
            }
            else
            {
                for(const auto &bug : bugs)
                {
                    if(bug->getPosition() == cell)
                    {
                        std::cout << " (" + bug->getType() + " " + std::to_string(bug->getId()) + ")";
                    }
                }
                std::cout << std::endl;
            }
            iter++;
        }
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
    std::ofstream file("../bugs_life_history_date_time.out");
    if(file)
    {
        for (const auto &bug : bugs)
        {
            file << bug->getHistory() << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Error when loading in the file." << std::endl;
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
    std::cout << "Bug " + std::to_string(id) + " not found." << std::endl;
}

void Board::tap()
{
    for (Bug* &bug : bugs)
    {
        if(bug->getAlive())
        {
            bug->move();
        }
    }
    board.clear();
    for (Bug* bug : bugs)
    {
        board[bug->getPosition()].push_back(bug);
    }
    fight();
}

void Board::fight()
{
    Bug* kingOfCell;
    std::vector<Bug*> bugsToFight;
    std::vector<Bug*> deadBugs;
    std::vector<Bug*> scavengersSurvived;

    for (const auto &cell : board)
    {
        if(cell.second.size() > 1)
        {
            bugsToFight.clear();
            deadBugs.clear();
            for (const auto &bug : cell.second)
            {
                if(bug->getAlive())
                {
                    bugsToFight.push_back(bug);
                }
                else
                {
                    deadBugs.push_back(bug);
                }
            }
            if(bugsToFight.size() > 1)
            {
                kingOfCell = bugsToFight.front();
                for (const auto &bug : bugsToFight)
                {
                    if(bug->getSize() > kingOfCell->getSize() ||
                       (bug->getSize() == kingOfCell->getSize() && rand()%2))
                    {
                        kingOfCell = bug;
                    }
                }
                if(kingOfCell->getType() != "Scavenger")
                {
                    for (auto &bug : bugsToFight)
                    {
                        if(bug != kingOfCell)
                        {
                            kingOfCell->eat(bug);
                        }
                    }
                }
            }
            for (const auto &bug : cell.second)
            {
                if(bug->getAlive() && bug->getType() == "Scavenger")
                {
                    scavengersSurvived.push_back(bug);
                }
            }
            if(!scavengersSurvived.empty())
            {
                kingOfCell = scavengersSurvived.front();
                for (const auto &scavenger : scavengersSurvived)
                {
                    if(scavenger->getSize() > kingOfCell->getSize() ||
                       (scavenger->getSize() == kingOfCell->getSize() && rand()%2))
                    {
                        kingOfCell = scavenger;
                    }
                }
                for (auto &corpse : deadBugs)
                {
                    kingOfCell->eatDead(corpse);
                }
            }
        }
    }
}

void Board::runSimulation()
{
    this->initializeBoard();
    int run = 2;
    int round = 0;
    while(run > 1 && round < 90)
    {
        this->tap();
        std::cout << "\nRound: " + std::to_string(++round) << std::endl;
        this->displayAllBugs();
        sleep(1);
        run = 0;
        for(Bug* bug : bugs)
        {
            if(bug->getAlive())
            {
                run++;
            }
        }
    }
    this->writeAllBugsHistory();
}