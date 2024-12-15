#ifndef WORD_N
#define WORD_N


// Imports
#include <iostream>             // For the std::cout override
#include <stdint.h>             // For the data format : uint64_t
#include <array>                // For the data array
#include <Word_n_unitary.hpp>   // For the unitary element
#include <cmath>                // FOr the data size calcul (with pow)
#include <iomanip>              // For display
#include <string>               // For the string setter
#include <algorithm>            // For string manipulation


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
    std::array<Word_n_unitary, static_cast<int>(pow(2, n - 5))> data;


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


    // Setter and getter
    void            reset();
    void            setData     (std::string data);
    void            setBloc     (const Word_n_unitary unitary_word, int index)          {this->data[index] = unitary_word;}
    Word_n_unitary  getBloc     (int index)                                     const   {return this->data[index];}
    int             dataSize    ()                                                      {return this->data.size();}
    int             binarySize  ()                                                      {return this->data.size() * 32;}


    // Fill a random value in the word
    void            randomize();


    // Display
    void            display(bool string_shape = false) const;


    // Modular calculation
    // TODO : need substraction, which need comparators


    // Overriding operators
    template<int m>
    Word_n<n+1>     operator+   (const Word_n<m>& word_n_2) const;

    template<int m>
    Word_n<n>       operator-   (const Word_n<m>& word_n_2) const;

    template<int m>
    Word_n<n+1>     operator*   (const Word_n<m>& word_n_2) const;
    Word_n<n>&      operator=   (std::string data);


    // Overriding comparators
    template<int m>
    bool            operator==  (const Word_n<m>& word_n_2) const;

    template<int m>
    bool            operator!=  (const Word_n<m>& word_n_2) const;

    template<int m>
    bool            operator>=  (const Word_n<m>& word_n_2) const;

    template<int m>
    bool            operator>   (const Word_n<m>& word_n_2) const;

    template<int m>
    bool            operator<=  (const Word_n<m>& word_n_2) const;

    template<int m>
    bool            operator<   (const Word_n<m>& word_n_2) const;
    
    bool            operator==  (std::string data)          const;
    bool            operator!=  (std::string data)          const;


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
 * Reset method
 */
template <int n>
void Word_n<n>::reset() {

    // Running through every word units
    for (Word_n_unitary& elt : data) {
        elt.reset();
    }

}


/**
 * String setter :
 * 
 * Since we can write strings that look likes hexa numbers, here is the setter.
 */
template <int n>
void Word_n<n>::setData(std::string data) {

    // Erasing 0x
    if (data.size() >= 2 && data.substr(0, 2) == "0x") {
        data.erase(0, 2);
    }


    // Erasing all space
    data.erase(std::remove(data.begin(), data.end(), ' '), data.end());


    /**
     * String length verification :
     * 
     * -> the string must fit into the word so it lengt must be lower
     * than :
     * number_of_word_units * length_supported_by_word_units
     * = 2^(n - 5) * 8
     */
    if (data.length() > (pow(2, n - 5) * 8)) {
        throw std::out_of_range("The string must fit into the word.");
    }


    // Data preprocessing : make it long by a multiple of 8
    if ((data.length() % 8) != 0) {
        data = std::string(8 - (data.length() % 8), '0') + data;
    }
    

    // Running through the <string>data, starting from the end
    int data_index = 0;
    for (int i = data.length(); i > 0; i -= 8) {

        // Start index calculation
        int start_index = i - 8;


        // Data attribution
        this->data[data_index].setData(data.substr(start_index, i - start_index));

        
        // Increment
        data_index ++;

    }


}


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
void Word_n<n>::display(bool string_shape) const {

    // Running through every word units
    for (int i = this->data.size() - 1; i != -1; i--) {

        // Display with the selected shape
        if (string_shape) {

            // If it is the first bloc to be printed
            if (i == this->data.size() - 1) {
                std::cout << "0x";
            }


            // Printing the word unit
            this->data[i].display(true);
            std::cout << " ";


        } else {

            // Display the data
            std::cout << std::setw(4) << std::setfill(' ') << i << " - ";
            this->data[i].display(false);


            // Spacing
            if ((i % 4) == 0) {
                std::cout << std::endl;
            } else {
                std::cout << "        ";
            }

        }

    }


    // Last spacing
    if (string_shape) {
        std::cout << std::endl;
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
        sum.setBloc(this->data[i] + word_n_2.getBloc(i), i);


        // Carry propagation
        sum.setBloc(sum.getBloc(i).getCarry(), i + 1);
        sum.getBloc(i).resetCarry();

    }


    // Retunring the sum
    return sum;

}


/**
 * Overriding the substratcion : not implemented yet
 * 
 */
template <int n>
template <int m>
Word_n<n> Word_n<n>::operator-(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     * -> A - B > 0, then A > B
     */
    static_assert(n == m, "The rank of the two operand must be equal.");


    // Sum creation
    Word_n<n> substraction;


    // Retunring the sum
    return *this;

}


/**
 * Overriding the multiplication :
 * 
 * 
 * 
 */
template <int n>
template <int m>
Word_n<n+1> Word_n<n>::operator*(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     * -> n and m respect the instanication rules, so therefore the result wich is 2*n
     * and so n = m < 16.
     */
    static_assert(n == m, "The rank of the two operand must be equal.");
    static_assert(n < 16, "The rank of the two operand must be lower than 16.");


    // Product creation
    Word_n<n+1> product;


    // Main vars
    unsigned int kmax   = product.dataSize();
    unsigned int limit  = kmax / 2;


    // Getting all word units to multiply
    for (unsigned int k = 0; k < kmax; k++) {

        // Generating (i, j) pairs for this round
        for (unsigned int i = 0; i < limit; i++) {
            unsigned int j = k - i;

            // Verifying if j is in the limit
            if (j < limit) {

                // Making the multiplication on word units
                product.setBloc(product.getBloc(k) + this->getBloc(i) * word_n_2.getBloc(j), k);

            }

        }


        // Carry propagation
        if ((k + 1) < kmax) {
            product.setBloc(product.getBloc(k).getCarry(), k + 1);
            product.getBloc(k).resetCarry();
        }

    }


    // Retunring the product
    return product;

}


/**
 * Data instanciation using '=' operator and string data
 */
template <int n>
Word_n<n>& Word_n<n>::operator=(std::string data) {

    // Data instanciation
    this->setData(data);    


    // Retunring itslef
    return *this;

}


/**
 * Internal data comparaison with another word_n
 */
template <int n>
template <int m>
bool Word_n<n>::operator==(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     */
    static_assert(n == m, "The rank of the two operand must be equal.");


    // Running through the data
    for (int i = 0; i < this->data.size(); i++) {

        // Word unit comparaison
        if (this->data[i] != word_n_2.getBloc(i)) {
            return false;
        }

    }
    return true;

}


/**
 * Internal data comparaison with another word_n
 */
template <int n>
template <int m>
bool Word_n<n>::operator!=(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     */
    static_assert(n == m, "The rank of the two operand must be equal.");


    // Running through the data
    for (int i = 0; i < this->data.size(); i++) {

        // Word unit comparaison
        if (this->data[i] == word_n_2.getBloc(i)) {
            return false;
        }

    }
    return true;

}


/**
 * Internal data comparaison with another word_n
 */
template <int n>
template <int m>
bool Word_n<n>::operator>=(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     */
    static_assert(n == m, "The rank of the two operand must be equal.");


    // Running through the data
    for (int i = 0; i < this->data.size(); i++) {

        // Word unit comparaison
        if (this->data[i] < word_n_2.getBloc(i)) {
            return false;
        }

    }
    return true;

}


/**
 * Internal data comparaison with another word_n
 */
template <int n>
template <int m>
bool Word_n<n>::operator>(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     */
    static_assert(n == m, "The rank of the two operand must be equal.");


    // Running through the data
    for (int i = 0; i < this->data.size(); i++) {

        // Word unit comparaison
        if (this->data[i] <= word_n_2.getBloc(i)) {
            return false;
        }

    }
    return true;

}


/**
 * Internal data comparaison with another word_n
 */
template <int n>
template <int m>
bool Word_n<n>::operator<=(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     */
    static_assert(n == m, "The rank of the two operand must be equal.");


    // Running through the data
    for (int i = 0; i < this->data.size(); i++) {

        // Word unit comparaison
        if (this->data[i] > word_n_2.getBloc(i)) {
            return false;
        }

    }
    return true;

}


/**
 * Internal data comparaison with another word_n
 */
template <int n>
template <int m>
bool Word_n<n>::operator<(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     */
    static_assert(n == m, "The rank of the two operand must be equal.");


    // Running through the data
    for (int i = 0; i < this->data.size(); i++) {

        // Word unit comparaison
        if (this->data[i] >= word_n_2.getBloc(i)) {
            return false;
        }

    }
    return true;

}


/**
 * Internal data comparaison with a string
 */
template <int n>
bool Word_n<n>::operator==(std::string data) const {

    // Putting the string data into an actual word_
    Word_n<n> word_n_2;
    word_n_2 = data;


    // Return the comparaison
    return (*this == word_n_2);

}


/**
 * Internal data comparaison with a string
 */
template <int n>
bool Word_n<n>::operator!=(std::string data) const {

    // Putting the string data into an actual word_
    Word_n<n> word_n_2;
    word_n_2 = data;


    // Return the comparaison
    return (*this != word_n_2);

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
        os << std::setw(4) << std::setfill(' ') << i << " - " << std::hex << word.data[i];


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
