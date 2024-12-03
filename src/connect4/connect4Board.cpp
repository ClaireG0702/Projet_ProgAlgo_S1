#include <iostream>
#include <array>

void drawConnect4Board(std::array<std::array<char, 6>, 7> tab) {
    std::cout << "\n";
    
    for(int i{0}; i < 6; i++) {
        for(int j{0}; j < 7; j++) {
            std::cout << "|" << tab[j][i];
        }
        std::cout << "|" << std::endl;
    }
}