#pragma once
#include <array>
#include "player.hpp"

struct Game {
    char winner;
    std::array<char, 9> tab;
};

bool checkIfCaseEmpty(const std::array<char, 9> const &tab, int const caseNumber);
bool checkWinner(const std::array<char, 9> &tab, Player const player);
void chooseCase(std::array<char, 9> &tab, Player const player);
void initializeTwoPlayersMode();
void initializeOnePlayerMode();