#include <iostream>
#include "../include/Word_n.hpp"
#include "Word_n_unitary.hpp"


int main() {

    std::cout << "Test" << std::endl;

    Word_n<8> word;

    // word.randomize();

    // word.setBloc(Word_n_unitary(0xFFFFFFFF), 0);
    // std::cout << word.getBloc(0) << std::endl;

    std::cout << word << std::endl;
    word.display();

    std::cout << "Oskur" << std::endl;

}