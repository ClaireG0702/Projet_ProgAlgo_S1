#include <iostream>
#include <array>

void drawGameBoard(std::array<char, 9> tab) {
    std::cout << "\n";
    
    for(int i{0}; i < 3; i++) {
        for(int j{0}; j < 3; j++) {
            std::cout << "|" << tab[i*3+j];
        }
        std::cout << "|" << std::endl;
    }
}