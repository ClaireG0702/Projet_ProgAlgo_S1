#include <iostream>
#include <string>

struct Player {
    std::string name {};
    char symbol {};
};

Player createPlayer() {
    Player player {};

    std::cout << "\n";
    std::cout << "Entrez un nom de joueur : ";
    std::cin >> player.name;
    std::cout << "Entrez un symbole (X ou O) : ";
    std::cin >> player.symbol;

    return player;
}