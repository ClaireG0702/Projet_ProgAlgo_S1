#pragma once
#include <array>
#include "player.hpp"

struct Game {
    char winner;
    int count;
    std::array<char, 9> tab;
};

bool checkIfCaseEmpty(std::array<char, 9> const &tab, int const caseNumber);
bool checkWinner(std::array<char, 9> const &tab, Player const player);
void chooseCase(std::array<char, 9> &tab, Player const player);
void initializeTwoPlayersMode();
void initializeOnePlayerMode();