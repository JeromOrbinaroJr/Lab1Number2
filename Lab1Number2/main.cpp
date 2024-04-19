#include <iostream>
#include <vector>
#include <locale.h>
#include <string>
#include <random>
#include "TicTacToe.h"
#include "GameChoice.h"
#define locale setlocale(LC_ALL, "Russian")

int main() {
    locale;
    TicTacToe game;
    char choiceMenu;

    game.printMenu();
    std::cin >> choiceMenu;

    try {
        if (choiceMenu != '1' && choiceMenu != '2' && choiceMenu != 'q') { throw choiceMenu;  }

        switch (choiceMenu) {
        case '1': {
            playAgainstComputer();
            break;
        }
        case '2': {
            playAgainstPlayer();
            break;
        }
        case 'q':
            std::cout << "Выход из игры.";
            break;
        }
    }
    catch (char choiceMenu) {
        std::cout << "Некорректный выбор.\n";
        return 0;
    }

    return 0;
}