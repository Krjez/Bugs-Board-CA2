#include <iostream>
#include <fstream>

#include "Board.h"
#include "BugTypes/Crawler.h"
#include "BugTypes/Hopper.h"

using namespace std;

Board createBoard();

int main() {
    srand(time(NULL));
    Board board = createBoard();
    bool run = true;
    cout << "Welcome to the bug board." << endl;

    while(run)
    {
        cout << "Choose an option (type 0-3):" << endl;
        cout << "0. End the program" << endl;
        cout << "1. Display all bugs" << endl;
        cout << "2. Find a bug (by id)" << endl;
        cout << "3. Tap the board" << endl;
        cout << "4. Display life history of all bugs" << endl;

        string read;
        cin >> read;
        int option = stoi(read);

        switch (option)
        {
            case 0:
                cout << "Thanks for playing." << endl;
                run = false;
                break;
            case 1:
                board.displayAllBugs();
                break;
            case 2:
                cout << "Input id of bug to be found:" << endl;
                int id;
                cin >> id;
                board.findBug(id);
                break;
            case 3:
                cout << "Board tapped. Bugs moved." << endl;
                board.tap();
                break;
            case 4:
                board.displayAllBugsHistory();
                break;
            default:
                cout << "Wrong input." << endl;
                break;
        }
    }
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