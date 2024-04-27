#include <iostream>

#include "Board.h"

using namespace std;

int main() {
    srand(time(NULL));
    Board board = Board();
    bool run = true;
    cout << "Welcome to the bug board." << endl;

    while(run)
    {
        cout << "\nChoose an option (type 0-3):" << endl;
        cout << "0. End the program" << endl;
        cout << "1. Initialize Bug board" << endl;
        cout << "2. Display all Bugs" << endl;
        cout << "3. Find a Bug (by id)" << endl;
        cout << "4. Tap the Board" << endl;
        cout << "5. Display life history of all Bugs" << endl;
        cout << "8. Exit (writes life history into file)" << endl;

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
                board.initializeBoard();
                break;
            case 2:
                board.displayAllBugs();
                break;
            case 3:
                cout << "Input id of bug to be found:" << endl;
                int id;
                cin >> id;
                board.findBug(id);
                break;
            case 4:
                cout << "Board tapped. Bugs moved." << endl;
                board.tap();
                break;
            case 5:
                board.displayAllBugsHistory();
                break;
            case 8:
                board.writeAllBugsHistory();
                break;
            default:
                cout << "Wrong input." << endl;
                break;
        }
    }
}