#include "GameChoice.h"
#include <string>
#include <iostream>
#include "TicTacToe.h"
#include <locale.h>
#include <random>
#define locale setlocale(LC_ALL, "Russian");

void playAgainstComputer() {
    std::random_device rd;
    std::mt19937 gen(rd());
    TicTacToe game;
    std::vector<char> gameBoard = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int player = 1;
    char symbol = 'X';

    std::string playerFirst;
    std::string playerSecond = "Компьютер";
    std::cout << "Введите ваше имя: ";
    std::cin >> playerFirst;

    while (true) {
        locale;
        system("cls || clear");
        game.displayBoard(gameBoard, playerFirst, playerSecond);

        if (player == 1) {
            int choice;
            std::cout << "Игрок " << player << " (" << symbol << "), введите номер ячейки: ";
            std::cin >> choice;

            if (choice < 1 || choice > 9 || gameBoard[choice - 1] == 'X' || gameBoard[choice - 1] == 'O') {
                std::cout << "Некорректный ход. Попробуйте еще раз." << std::endl;
                continue;
            }
            gameBoard[choice - 1] = symbol;
        }
        else {
            std::uniform_int_distribution<> dist(0, 8);
            int choice = -1;
            if (game.ComputerMove(gameBoard) != -1) {
                choice = game.ComputerMove(gameBoard);
            }
            else {
                do {
                    choice = dist(gen);
                } while (gameBoard[choice] == 'X' || gameBoard[choice] == 'O');
            }
            gameBoard[choice] = symbol;
        }

        player = (player == 1) ? 2 : 1;
        symbol = (symbol == 'X') ? 'O' : 'X';

        system("cls || clear");
        game.displayBoard(gameBoard, playerFirst, playerSecond);

        if (game.checkWin(gameBoard, 'X')) {
            std::cout << "Победил " << playerFirst << " (X)!\n";
            break;
        }
        else if (game.checkWin(gameBoard, 'O')) {
            if (playerSecond == "Компьютер") {
                std::cout << "Победил " << playerSecond << " (O)!\n";
            }
            break;
        }
        else if (game.nobodyWin(gameBoard) == 9) {
            std::cout << "Победила Дружба!\n";
            break;
        }
    }
}

void playAgainstPlayer() {
    TicTacToe game;
    std::vector<char> gameBoard = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int player = 1;
    char symbol = 'X';

    std::string playerFirst;
    std::string playerSecond;
    std::cout << "Введите имя первого игрока: ";
    std::cin >> playerFirst;
    std::cout << "Введите имя второго игрока: ";
    std::cin >> playerSecond;
    while (true) {
        locale;
        system("cls || clear");
        game.displayBoard(gameBoard, playerFirst, playerSecond);
        int choice;
        std::cout << "Игрок " << player << " (" << symbol << "), введите номер ячейки: ";
        std::cin >> choice;

        if (choice < 1 || choice > 9 || gameBoard[choice - 1] == 'X' || gameBoard[choice - 1] == 'O') {
            std::cout << "Некорректный ход. Попробуйте еще раз." << std::endl;
            continue;
        }

        gameBoard[choice - 1] = symbol;
        player = (player == 1) ? 2 : 1;
        symbol = (symbol == 'X') ? 'O' : 'X';

        system("cls || clear");
        game.displayBoard(gameBoard, playerFirst, playerSecond);
        if (game.checkWin(gameBoard, 'X')) {
            std::cout << "Победил " << playerFirst << "(X)!\n";
            break;
        }
        else if (game.checkWin(gameBoard, 'O')) {
            std::cout << "Победил " << playerSecond << "(O)!\n";
            break;
        }
        else if (game.nobodyWin(gameBoard) == 9) {
            std::cout << "Победила Дружба!\n";
            break;
        }
    }
}