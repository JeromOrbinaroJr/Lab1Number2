#pragma once
#include <vector>
#include <string>

class TicTacToe {
public:
    TicTacToe();

    std::vector<char> getGameBoard() const;
    int getCurrentPlayer() const;
    char getCurrentSymbol() const;
    std::string getPlayerFirst() const;
    std::string getPlayerSecond() const;

    void setGameBoard(const std::vector<char>& newBoard);
    void setCurrentPlayer(int player);
    void setCurrentSymbol(const char& symbol);
    void setPlayerFirst(const std::string& first);
    void setPlayerSecond(const std::string& second);

    void displayBoard(std::vector<char> board, std::string playerFirst, std::string playerSecond) const;
    int ComputerMove(const std::vector<char>& board);
    bool checkWin(const std::vector<char>& board, char symbol);
    int nobodyWin(const std::vector<char>& board);
    void printMenu();

private:
    std::vector<char> gameBoard;
    int currentPlayer;
    char currentSymbol;
    std::string playerFirst;
    std::string playerSecond;
};