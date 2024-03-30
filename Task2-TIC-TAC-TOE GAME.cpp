#include <iostream>
#include <vector>

using namespace std;

void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameFinished = false;
    bool playAgain = true;
    char playAgainChoice;

    while (playAgain) {
        initializeBoard(board);

        while (!gameFinished) {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;

                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameFinished = true;
                } else if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                    gameFinished = true;
                } else {
                    switchPlayer(currentPlayer);
                }
            } else {
                cout << "That cell is already occupied. Try again." << endl;
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgainChoice;
        if (playAgainChoice != 'y' && playAgainChoice != 'Y') {
            playAgain = false;
        } else {
            gameFinished = false;
            currentPlayer = 'X';
        }
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2" << endl;
    cout << " +-+-+-+" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << "|";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << "|";
        }
        cout << endl;
        cout << " +-+-+-+" << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
