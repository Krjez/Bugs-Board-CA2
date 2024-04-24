#include <iostream>
#include <fstream>

#include "Board.h"
#include "BugTypes/Crawler.h"
#include "BugTypes/Hopper.h"

using namespace std;

Board createBoard();

int main()
{
    Board board = createBoard();
    board.displayAllBugs();




}

/**
 * Board creation and populating with bugs
 */
Board createBoard()
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
                board.addBug({x,y},new Crawler(id,{x,y},direction,size));
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
                board.addBug({x,y},new Hopper(id,{x,y},direction,size,hopLength));
            }
            else
            {
                cout << "Problem with loading in a bug" << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "Error when loading in the file." << endl;
    }
    return board;
}