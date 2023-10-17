
#include "main.h"

int main() {
    srand(unsigned (time(nullptr)));
    playGame();
    return 0;
}

/* SET UP FUNCTIONS*/

void setUpGame() {
    setUpBoard();
    setUpPlayers();

}

/* GAME FUNCTIONS */

void playGame() {
    setUpGame();

    while (! (colIsEmpty(theDice.getXLoc()) && rowIsEmpty(theDice.getYLoc()))) {
        makeAMove(player1);
        system("pause");
        system("cls");
        makeAMove(player2);
    }
    cout << theBoard->getDetails(&theDice);
    endGame();
}

void endGame() {
    Player winner;
    if (player1.getScore() > player2.getScore()) {
        winner = player1;
    } else {
        if (player2.getScore() > player1.getScore()) {
            winner = player2;
        } else {
            cout << "It's a draw!\n";
        }
    }
    if (winner.getName() != "NONE") {
        cout << "The winner is: " << winner.getName() << " with a score of: " << winner.getScore() << "!\n";

    }
}
bool colIsEmpty(int col) {
    for (int row = 0; row < DIMENSION; row ++) {
        //cout << "check if has counter at row col " << row << " " << col << " pix: " << theBoard->getPix(col, row) << " " << theBoard->getObject(col, row)->getPoints() << endl;
        if (theBoard->getObject(col, row)->getPoints() > 0){
            //cout << "row col: " << row << " " << col << endl;
            return false;
        }
    }
    return true;
}

bool rowIsEmpty(int row) {
    for (int col = 0; col < DIMENSION; col ++) {
        //cout << "check if has counter at row col " << row << " " << col << " pix: " << theBoard->getPix(col, row) << " " << theBoard->getObject(col, row)->getPoints() << endl;
        if (theBoard->getObject(col, row)->getPoints()>0){
            //cout << "row col: " << row << " " << col << endl;

            return false;
        }
    }
    return true;
}

bool inBoard(int x, int y) {
    return (0 <= x < DIMENSION && 0 <= y < DIMENSION);
}
bool hasCounter(int ID, int increment) {
    int diceX = theDice.getXLoc();
    int diceY = theDice.getYLoc();
    if (ID == 1) {
        if (inBoard(diceX, diceY + increment)) {
            cout << "check if has counter at x y " << diceX << " " << diceY << endl;
            return theBoard->getObject(diceX, diceY+increment)->getPoints() > 0;
        }
    } else {
        if (inBoard(diceX + increment, diceY)) {
            return theBoard->getPix(diceX+increment, diceY) != '.';
        }
    }
    return false;
}

void makeAMove(Player &player) {

    string userInput;
    int ID = player.getID();
    cout << "Dice x y: " << theDice.getXLoc() << " " << theDice.getYLoc() << endl;
    cout << theBoard->getDetails(&theDice);

    bool end = (ID == 1)? colIsEmpty(theDice.getXLoc()): rowIsEmpty(theDice.getYLoc());
    if (end) {
        if (ID == 1) {
            cout << "There's no counter in that col. Your turn is skipped."<< endl;
        } else {
            cout << "There's no counter in that row. Your turn is skipped."<< endl;

        }
    }
    int increment = 0;
    while (not end) {
        cout << player.getDetails();
        cout << "Enter your move:  ";
        cin >> userInput;
        increment = stoi(userInput);
        if (hasCounter(ID, increment)) {
            // re
            theBoard->updateLocation(new Object('.', theDice.getXLoc(), theDice.getYLoc()));
            theDice.moveDice(increment, ID);
            cout << "new Dice position xy: " << theDice.getXLoc() << " " << theDice.getYLoc() << endl;
            int points = theBoard->getObject(theDice.getXLoc(), theDice.getYLoc())->getPoints();
            player.updateScore(points);
            end = true;
        } else {
            cout << "There's no counter at that position.\n";
        }

    }
    theBoard->updateLocation(&theDice);
}



void setUpPlayers() {
    string name1 = askForString("Enter player 1 name: " );
    string name2 = askForString("Enter player 2 name: ");
    player1 = Player(name1, 0, 1);
    player2 = Player(name2, 0, 2);
    cout << player1.getDetails();
    cout << player2.getDetails();
}

void setUpBoard() {
    theBoard = new Board();
    setUpDice();
    setUpCounters();
}

void setUpDice() {

    int diceX = rand() % DIMENSION;
    int diceY = rand() % DIMENSION;
    theDice =  Dice('+', diceX, diceY);
    theBoard->setLocation('+', diceX, diceY);
}

void setUpCounters() {
    //int counterNumbers = rand()%25 + 25;
    int counterNumbers = 5;
    Object* counter = nullptr;
    for (int i = 0; i < counterNumbers; i ++) {
        int x = rand() % DIMENSION;
        int y = rand() % DIMENSION;
        int index = rand()%NCOLORS;
        char color = colors[index];
        int value = (index+1)*5;
        counter =  new Counter(color, value, x, y);
        theBoard->updateLocation(counter);
    }
}

string askForString(string question) {
    string userInput;
    cout << question;
    getline(cin, userInput);
    cin.clear();
    return userInput;
}


