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

    // Running through every word units
    for (Word_n_unitary& elt : data) {
        elt.randomize();
    }

}


/**
 * Display : Display the whole word (with the hidden part of all word units)
 */
template <int n>
void Word_n<n>::display() const {

    // Running through every word units
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
 * Overriding the addition :
 * 
 * 
 * The addition is pretty simple :
 * - we make it on each word unit using their properties
 * 
 * In fact, each word unit is on 64bit but only the 32bit lower store the data itslef. The half top, is used
 * to save the carry, which is propagate after :
 * 
 *                63      31      0
 *                |       |       |
 * Bloc 1 ->     [    0   . data_1 ]
 * Bloc 2 ->     [    0   . data_2 ]
 * 
 * Bloc 1 + 2 -> [ carry  .data_1+2]
 * 
 */
template <int n>
template <int m>
Word_n<n+1> Word_n<n>::operator+(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     * -> n and m respect the instanication rules, so therefore the result wich is 2*n
     * and so n = m < 16.
     */
    static_assert(n == m, "The rank of the two operand must be equal.");
    static_assert(n < 16, "The rank of the two operand must be lower than 16.");


    // Sum creation
    Word_n<n+1> sum;


    // Running through every word units
    for (int i = 0; i != this->data.size(); i++) {

        // Adding up word units
        sum.setBloc(this->data[i] + word_n_2.getBloc(i));

    }


    // Retunring the sum
    return sum;

}


/**
 * Overriding Cout :
 * 
 * Display only the usable data (each 32bit long lower part of all word units)
 */
template <int m>
std::ostream& operator<<(std::ostream& os, const Word_n<m>& word) {

    // Running through every word units
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
