#include <iostream>
#include <fstream>

#include "Board.h"
#include "BugTypes/Crawler.h"
#include "BugTypes/Hopper.h"

using namespace std;

void createBoard();

int main()
{
    createBoard();




}

/**
 * Board creation and populating with bugs
 */
void createBoard()
{
    Board board = Board();

    ifstream file("../bugs.txt");

    if(file)
    {
        const char delimiter = ';';
        while(!file.eof())
        {
            string type;
            string value;
            getline(file,type,delimiter);
            if(type == "C")
            {
                int id; int x; int y; int direction; int size;
                getline(file,value,delimiter);
                id = stoi(value);
                getline(file,value,delimiter);
                x = stoi(value);
                getline(file,value,delimiter);
                y = stoi(value);
                getline(file,value,delimiter);
                direction = stoi(value);
                getline(file,value,delimiter);
                size = stoi(value);
                Crawler c = Crawler(id, x, y, direction, size);

            }
        }
        file.close();
    }
    else
    {
        cout << "Error when loading in the file." << endl;
    }

}