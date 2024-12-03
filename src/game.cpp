#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include "player.hpp"
#include "board.hpp"

struct Game {
    std::string winner {" "};
    int count {0};
    std::array<char, 9> tab {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
};

bool checkIfCaseEmpty(std::array<char, 9> const &tab, int const caseNumber) {
    return tab[caseNumber - 1] == ' ';
}

bool checkWinner(std::array<char, 9> const &tab, Player const player) {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Lignes
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Colonnes
        {0, 4, 8}, {2, 4, 6}             // Diagonales
    };

    for(const auto& pattern : winPatterns) {
        if(tab[pattern[0]] == player.symbol && tab[pattern[1]] == player.symbol && tab[pattern[2]] == player.symbol) {
            return true;
        }
    }

    return false;
}

void chooseCase(std::array<char, 9> &tab, Player const player) {
    int caseNumber {};
    std::string input;

    do {
        std::cout << player.name << ", choisissez une case (1-9) : ";
        std::cin >> input;

        if (input.length() != 1 || !std::isdigit(input[0])) {
            std::cout << "Veuillez entrer un chiffre valide (1-9).\n";
            continue;
        }

        caseNumber = input[0] - '0';

        if (caseNumber < 1 || caseNumber > 9) {
            std::cout << "Veuillez choisir un numero valide (1-9).\n";
        } else if (!checkIfCaseEmpty(tab, caseNumber)) {
            std::cout << "Cette case est deja occupee.\n";
        } else {
            break;
        }
    } while (true);

    tab[caseNumber - 1] = player.symbol;
}

void randomCase(std::array<char, 9> &tab, Player const player) {
    int caseNumber {};

    do {
        srand(time(0));
        caseNumber = (rand() % 9) + 1;

        if (caseNumber < 1 || caseNumber > 9) {
            std::cout << "Erreur case non valide.\n";
        } else if (!checkIfCaseEmpty(tab, caseNumber)) {
            // std::cout << "Cette case est deja occupee.\n";
        } else {
            break;
        }
    } while (true);

    tab[caseNumber - 1] = player.symbol;
}

void initializeTwoPlayersMode() {
    Game game {};

    Player player1 = createPlayer();
    Player player2 = createPlayer();

    while (player1.symbol == player2.symbol) {
        std::cout << "Le symbole est deja utilise par le joueur 1. Choisissez un autre symbole : ";
        std::cin >> player2.symbol;
    }

    drawGameBoard(game.tab);

    while (game.count < 9 && game.winner == " ") {
        Player currentPlayer = (game.count % 2 == 0) ? player1 : player2;
        chooseCase(game.tab, currentPlayer);
        drawGameBoard(game.tab);

        if (checkWinner(game.tab, currentPlayer)) {
            game.winner = currentPlayer.name;
            break;
        }

        game.count++;
    }

    if (game.winner != " ") {
        std::cout << game.winner << " a gagne !\n";
    } else {
        std::cout << "Match nul !\n";
    }
}

void initializeOnePlayerMode() {
    Game game {};

    Player player2 {"IA", 64};
    Player player1 = createPlayer();

    while (player1.symbol == player2.symbol) {
        std::cout << "Le symbole est deja utilise par l'IA. Choisissez un autre symbole : ";
        std::cin >> player1.symbol;
    }

    drawGameBoard(game.tab);

    while (game.count < 9 && game.winner == " ") {
        Player currentPlayer = (game.count % 2 == 0) ? player1 : player2;

        if(game.count % 2 == 0) {
            chooseCase(game.tab, currentPlayer);
        } else {
            randomCase(game.tab, currentPlayer);
        }

        drawGameBoard(game.tab);

        if (checkWinner(game.tab, currentPlayer)) {
            game.winner = currentPlayer.name;
            break;
        }

        game.count++;
    }

    if (game.winner != " ") {
        std::cout << game.winner << " a gagne !\n";
    } else {
        std::cout << "Match nul !\n";
    }
}
