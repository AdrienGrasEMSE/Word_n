#ifndef WORD_N
#define WORD_N


// Imports
#include <iostream>             // For the std::cout override
#include <stdint.h>             // For the data format : uint64_t
#include <array>                // For the data array
#include "Word_n_unitary.hpp"   // For the unitary element


/**
 * Class Word_n :
 * 
 * WARNING : n must be between 5 and 16...
 * 
 * Class which store 2^n bit data, using n Word_n_unitary object. This class
 * mais purpose is to be compatible with operation such as addition or multiplication.
 * 
 * 
 * @author Adrien GRAS
 */
template<int n>
class Word_n {
private:

    // The data array
    std::array<Word_n_unitary, n>  data;


public:

    /**
     * n verification :
     * 
     * If n is lower than 5, just use a classic uint16_t
     * 
     * To prevent to big variable, I made a max size limit :
     * -> If n greater than 16 (you can alredy do a loads of things with 2^16bits)
     *  the compilator refuse the instanciation.
     */
    static_assert(n >= 5,   "n must be greater than 5, just use uint16_t...");
    static_assert(n <= 16,  "n must be lower than 16, to prevent too big variables");


    // Constructors
    Word_n   ();


    // Destructor
    ~Word_n  ();


    // Unitary word setter and getter
    void            setBloc(const Word_n_unitary unitary_word, long unsigned int index) {this->data[index] = unitary_word;}
    Word_n_unitary  getBloc(long unsigned int index) const                              {return this->data[index];}


    // Fill a random value in the word
    void            randomize();


    // Display
    void            display() const;


    // Overriding operators
    template<int m>
    Word_n<n+1>     operator+(const Word_n<m>& word_n_2) const;
    template<int m>
    Word_n<n>       operator-(const Word_n<m>& word_n_2) const;
    template<int m>
    Word_n<n+1>     operator*(const Word_n<m>& word_n_2) const;

    // Overriding Cout for display
    template<int m>
    friend std::ostream& operator<<(std::ostream& os, const Word_n<m>& word);

};
#endif // WORD_N




/**
 * ================================================================================================
 * Constructors and Destructors
 * ================================================================================================
 */

/**
 * Default Constructor
 */
template <int n>
Word_n<n>::Word_n() {
    // Nothing to do here
}


/**
 * Destructor
 * 
 */
template <int n>
Word_n<n>::~Word_n() {
    // Nothing to do here
}


/**
 * ================================================================================================
 * Utilities
 * ================================================================================================
 */

/**
 * Randomize : randomize every word units
 */
template <int n>
void Word_n<n>::randomize() {

    // Running throug every word units
    for (Word_n_unitary& elt : data) {
        elt.randomize();
    }

}


/**
 * Display : Display the whole word (with the hidden part of all word units)
 */
template <int n>
void Word_n<n>::display() const {

    // Running throug every word units
    for (int i = this->data.size() - 1; i != -1; i--) {

        // Display the data
        std::cout << "Bloc : " << i << " - ";
        this->data[i].display(false);


        // Spacing
        if ((i % 4) == 0) {
            std::cout << std::endl;
        } else {
            std::cout << "        ";
        }

    }

}




/**
 * ================================================================================================
 * Operators
 * ================================================================================================
 */

/**
 * Overriding Cout :
 * 
 * Display only the usable data (each 32bit long lower part of all word units)
 */
template <int m>
std::ostream& operator<<(std::ostream& os, const Word_n<m>& word) {

    // Running throug every word units
    for (int i = word.data.size() - 1; i != -1; i--) {

        // Display the data
        os << "Bloc : " << i << " - " << std::hex << word.data[i];


        // Spacing
        if ((i % 4) == 0) {
            std::cout << std::endl;
        } else {
            std::cout << "        ";
        }

    }


    // Returning the stream
    return os;
}
