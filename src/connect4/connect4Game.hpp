#pragma once
#include <array>
#include "./../player.hpp"

struct Connect4Game {
    char winner;
    std::array<std::array<char, 6>, 7> tab;
};

void initializeConnect4TwoPlayers();
void initializeConnect4OnePLayer();