#include <iostream>
#include "game.hpp"

int main() {
    char gameMode {};

    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;

    while(gameMode != '1' && gameMode != '2') {
        std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
        std::cout << "1. Deux joueurs" << std::endl;
        std::cout << "2. Un joueur contre l'IA" << std::endl;
        std::cin >> gameMode;
    }

    // Clean terminale

    if(gameMode == '1') {
        initializeTwoPlayersMode();
    } else {
        initializeOnePlayerMode();
    }

    return 0;
}