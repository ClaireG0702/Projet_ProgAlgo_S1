#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include "./../player.hpp"
#include "connect4Board.hpp"

struct Connect4Game {
    std::string winner {" "};
    int count {0};
    std::array<std::array<char, 6>, 7> tab = {
        {{' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}}
    };
};

bool checkIfColumnFull(std::array<std::array<char, 6>, 7> const &tab, int const columnNumber) {
    int counter {0};

    for(int i{0}; i < 6; i++) {
        if(tab[columnNumber-1][i] != ' ') {
            counter++;
        }
    }

    return counter == 6;
}

void addPlayerSymbol(std::array<std::array<char, 6>, 7> &tab, int const columnNumber, char symbol) {
    for(int i{6}; i > 0; i--) {
        if(tab[columnNumber-1][i-1] == ' ') {
            tab[columnNumber-1][i-1] = symbol;
            break;
        }
    }
}

void chooseColumn(std::array<std::array<char, 6>, 7> &tab, Player const player) {
    int columnNumber {};
    std::string input {};

    do {
        std::cout << player.name << ", choississez une colonne (1-7) : ";
        std::cin >> input;

        if(input.length() != 1 || !std::isdigit(input[0])) {
            std::cout << "Veuillez entrer un chiffre valide (1-7).\n";
            continue;
        }

        columnNumber = input[0] - '0';

        if(columnNumber < 1 || columnNumber > 7) {
            std::cout << "Veuillez choisir un chiffre valide (1-7).\n";
        } else if(checkIfColumnFull(tab, columnNumber)) {
            std::cout << "Cette colonne est deja complete.\n";
        } else {
            break;
        }
    } while(true);

    addPlayerSymbol(tab, columnNumber, player.symbol);
}

void randomColumn(std::array<std::array<char, 6>, 7> &tab, Player const player) {
    int columnNumber {};

    do {
        srand(time(0));
        columnNumber = (rand() % 7) + 1;

        if(columnNumber < 1 || columnNumber > 7) {
            std::cout << "Erreur colonne non valide.\n";
        } else if(checkIfColumnFull(tab, columnNumber)) {
            // std::cout << "Cette colonne est deja complete.\n";
        } else {
            break;
        }
    } while(true);

    addPlayerSymbol(tab, columnNumber, player.symbol);
}

bool checkConnect4Winner(std::array<std::array<char, 6>, 7> const &tab, Player const player) {
    int index {0};

    for(int i{0}; i < 2; i++) {
        for(int j{0}; j < 7; j++) {
            if(tab[i][j] == player.symbol && tab[i+1][j] == player.symbol && tab[i+2][j] == player.symbol && tab[i+3][j] == player.symbol) {
                return true;
            }
        }
    }
    for(int i{0}; i < 6; i++) {
        for(int j{0}; j < 3; j++) {
            if(tab[i][j] == player.symbol && tab[i][j+1] == player.symbol && tab[i][j+2] == player.symbol && tab[i][j+3] == player.symbol) {
                return true;
            }
        }
    }
    for(int i{0}; i < 2; i++) {
        for(int j{0}; j < 3; j++) {
            if(tab[i][j] == player.symbol && tab[i+1][j+1] == player.symbol && tab[i+2][j+2] == player.symbol && tab[i+3][j+3] == player.symbol){
                return true;
            }
            if(tab[i+3][j] == player.symbol && tab[i+2][j+1] == player.symbol && tab[i+1][j+2] == player.symbol && tab[i][j+3] == player.symbol) {
                return true;
            }
        }
    }
    
    return false;
}

void initializeConnect4TwoPlayers() {
    Connect4Game game {};

    Player player1 = createPlayer();
    Player player2 = createPlayer();

    while (player1.symbol == player2.symbol) {
        std::cout << "Le symbole est deja utilise par le joueur 1. Choisissez un autre symbole : ";
        std::cin >> player2.symbol;
    }
    
    drawConnect4Board(game.tab);

    while(game.count < 42 && game.winner == " ") {
        Player currentPlayer = (game.count % 2 == 0) ? player1 : player2;
        chooseColumn(game.tab, currentPlayer);
        drawConnect4Board(game.tab);

        if(checkConnect4Winner(game.tab, currentPlayer)) {
            game.winner = currentPlayer.name;
            break;
        }

        game.count++;
    }

    if(game.winner != " ") {
        std::cout << game.winner << " a gagne !\n";
    } else {
        std::cout << "Match nul !\n";
    }
}

void initializeConnect4OnePLayer() {
    Connect4Game game {};

    Player player2 = {"IA", 64};
    Player player1 = createPlayer();

    while (player1.symbol == player2.symbol) {
        std::cout << "Le symbole est deja utilise par l'IA. Choisissez un autre symbole : ";
        std::cin >> player1.symbol;
    }
    
    drawConnect4Board(game.tab);

    while(game.count < 42 && game.winner == " ") {
        Player currentPlayer = (game.count % 2 == 0) ? player1 : player2;
        
        if(game.count % 2 == 0) {
            chooseColumn(game.tab, currentPlayer);
        } else {
            randomColumn(game.tab, currentPlayer);
        }

        drawConnect4Board(game.tab);

        if(checkConnect4Winner(game.tab, currentPlayer)) {
            game.winner = currentPlayer.name;
            break;
        }

        game.count++;
    }

    if(game.winner != " ") {
        std::cout << game.winner << " a gagne !\n";
    } else {
        std::cout << "Match nul !\n";
    }
}