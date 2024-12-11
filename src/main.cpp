#include <iostream>
#include "game.hpp"
#include "connect4/connect4Game.hpp"

int main() {
    char gameMode {};

    std::cout << "Bienvenue sur le menu de jeux !" << std::endl;

    while(gameMode != '1' && gameMode != '2' && gameMode != '3' && gameMode != '4') {
        std::cout << "Veuillez choisir un jeu :\n";
        std::cout << "1. TicTacToe - Deux joueurs\n";
        std::cout << "2. TicTacToe - Un joueur contre l'IA\n";
        std::cout << "3. Puissance 4 - Deux joueurs\n";
        std::cout << "4. Puissance 4 - Un joueur contre l'IA\n";
        std::cin >> gameMode;
    }

    switch (gameMode) {
        case '1':
            initializeTwoPlayersMode();
            break;
        case '2':
            initializeOnePlayerMode();
            break;
        case '3':
            initializeConnect4TwoPlayers();
            break;
        case '4':
            initializeConnect4OnePLayer();
            break;
        default:
            break;
    }

    return 0;
}