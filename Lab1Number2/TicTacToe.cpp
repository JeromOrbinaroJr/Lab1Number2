#include "TicTacToe.h"
#include <random>
#include <iostream>

TicTacToe::TicTacToe() : currentPlayer(1), currentSymbol('X') {}

std::vector<char> TicTacToe::getGameBoard() const { return gameBoard; }
int TicTacToe::getCurrentPlayer() const { return currentPlayer; }
char TicTacToe::getCurrentSymbol() const { return currentSymbol; }
std::string TicTacToe::getPlayerFirst() const { return playerFirst; }
std::string TicTacToe::getPlayerSecond() const { return playerSecond; }

void TicTacToe::setGameBoard(const std::vector<char>& newBoard) { gameBoard = newBoard; }
void TicTacToe::setCurrentPlayer(int player) { currentPlayer = player; }
void TicTacToe::setCurrentSymbol(const char& symbol) { currentSymbol = symbol; }
void TicTacToe::setPlayerFirst(const std::string& first) { playerFirst = first; }
void TicTacToe::setPlayerSecond(const std::string& second) { playerSecond = second; }

void TicTacToe::displayBoard(std::vector<char> board, std::string playerFirst, std::string playerSecond) const {
    std::cout << playerFirst << " VS " << playerSecond << std::endl;
    std::cout << "+------+------+------+" << std::endl;
    for (int i = 0; i < 9; i += 3) {
        std::cout << "|  " << board[i] << "   |  " << board[i + 1] << "   |  " << board[i + 2] << "   |" << std::endl;
        std::cout << "+------+------+------+" << std::endl;
    }
}

int TicTacToe::ComputerMove(const std::vector<char>& board) {
    char playerSymbol = 'X';

    // Проверяем, есть ли возможность блокировать ходы игрока X, чтобы предотвратить его победу
    for (int i = 0; i < 3; ++i) {
        int countX = 0;
        int choice = -1;
        for (int j = 0; j < 3; ++j) {
            if (board[i * 3 + j] == playerSymbol) {
                countX++;
            }
            else if (board[i * 3 + j] != playerSymbol && board[i * 3 + j] != 'O') {
                choice = i * 3 + j;
            }
            if (countX == 2 && choice != -1) {
                return choice;
            }
        }
    }

    // То же самое для столбцов
    for (int i = 0; i < 3; ++i) {
        int countX = 0;
        int choice = -1;
        for (int j = 0; j < 3; ++j) {
            if (board[i + j * 3] == playerSymbol) {
                countX++;
            }
            else if (board[i + j * 3] != playerSymbol && board[i + j * 3] != 'O') {
                choice = i + j * 3;
            }
            if (countX == 2 && choice != -1) {
                return choice;
            }
        }
    }

    // Диагонали
    for (int i = 0; i < 3; ++i) {
        int countX = 0;
        int choice = -1;
        if (board[i * 4] == playerSymbol) {
            countX++;
        }
        else if (board[i * 4] != playerSymbol && board[i * 4] != 'O') {
            choice = i * 4;
        }
        if (countX == 2 && choice != -1) {
            return choice;
        }
    }
    for (int i = 0; i < 3; ++i) {
        int countX = 0;
        int choice = -1;
        if (board[(i * 2) + 2] == playerSymbol) {
            countX++;
        }
        else if (board[(i * 2) + 2] != playerSymbol && board[(i * 2) + 2] != 'O') {
            choice = (i * 2) + 2;
        }
        if (countX == 2 && choice != -1) {
            return choice;
        }
    }

    // Если нет возможности заблокировать ход игрока X, выбираем случайный ход
    std::vector<int> emptyCells;
    for (int i = 0; i < 9; ++i) {
        if (board[i] != 'X' && board[i] != 'O') {
            emptyCells.push_back(i);
        }
    }
    if (!emptyCells.empty()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, emptyCells.size() - 1);
        return emptyCells[dis(gen)];
    }
    return -1;
}

bool TicTacToe::checkWin(const std::vector<char>& board, char symbol) {
    for (int i = 0; i < 3; ++i) { // победные комбинации для горизонтали и вертикали 
        if ((board[i * 3] == symbol && board[i * 3 + 1] == symbol && board[i * 3 + 2] == symbol) ||
            (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol)) {
            return true;
        }
    }
    // победные комбинации для диагонали
    if ((board[0] == symbol && board[4] == symbol && board[8] == symbol) ||
        (board[2] == symbol && board[4] == symbol && board[6] == symbol)) {
        return true;
    }
    return false;
}

int TicTacToe::nobodyWin(const std::vector<char>& board) {
    int count = 0;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == 'X' || board[i] == 'O') {
            count++;
        }
    }
    return count;
}

void TicTacToe::printMenu() {
    std::cout << "TicTacToe Game\n\n";
    std::cout << "1) Play a Single Player game\n";
    std::cout << "2) Play a Multiplayer game\n";
    std::cout << "q) Quit the game\n";
}
