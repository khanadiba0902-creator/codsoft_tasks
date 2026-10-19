#include <iostream>
#include <limits>
using namespace std;

char board[9];

void resetBoard() {
    for (int i = 0; i < 9; i++) board[i] = ' ';
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
        if (i < 6) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char p) {
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},
                      {0,3,6},{1,4,7},{2,5,8},
                      {0,4,8},{2,4,6}};
    for (auto& w : wins)
        if (board[w[0]] == p && board[w[1]] == p && board[w[2]] == p)
            return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 9; i++)
        if (board[i] == ' ') return false;
    return true;
}

int getMove(char player) {
    int pos;
    while (true) {
        cout << "Player " << player << ", choose position (1-9): ";
        if (!(cin >> pos)) {
            cout << "Enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (pos < 1 || pos > 9) {
            cout << "Choose a number from 1 to 9.\n";
        } else if (board[pos - 1] != ' ') {
            cout << "That spot is taken.\n";
        } else {
            return pos - 1;
        }
    }
}

void playGame() {
    resetBoard();
    char player = 'X';
    cout << "=== Tic-Tac-Toe ===\n";
    cout << "Positions:\n 1 | 2 | 3\n 4 | 5 | 6\n 7 | 8 | 9\n";

    while (true) {
        displayBoard();
        board[getMove(player)] = player;

        if (checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    char again;
    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
