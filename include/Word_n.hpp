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
 * WARNING : n must be a multiple of 32
 * 
 * Class which store n * 32 bit data, using n Word_n_unitary object. This class
 * purpose is to be compatible with operation such as addition or multiplication.
 * 
 * 
 * @author Adrien GRAS
 */
template<int n>
class Word_n {
private:

    // The data array
    std::array<Word_n_unitary, static_cast<int>(n / 32)> data;


public:

    /**
     * n verification :
     * 
     * We store data into 32 bit long storage, so n must be a multiple of 32
     * 
     * If n is lower than 64, just use a classic uint16_t
     * 
     * To prevent to big variable, I made a max size limit :
     * -> The maximum is 65 536 bits.
     */
    static_assert(n % 32 == 0,  "n must be a multiple of 32...");
    static_assert(n >= 64,      "n must be greater than 64, just use uint16_t...");
    static_assert(n <= 65536,   "n must be lower than 65536, to prevent too big variables");


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


    // Fill a random value in the word
    void            randomize();


    // Display
    void            display     (bool string_shape = false) const;


    // Word<n+1> and Word<n-1> cast
    Word_n<2 * n>   upSize()    const;
    Word_n<n / 2>   downSize()  const;


    // Crop another Word<m> with m >= n
    template<int m>
    void            crop        (const Word_n<m>& word_n_2);


    // Max-out value method
    static Word_n   maxValue();


    // Null value
    static Word_n<n> nullValue();


    // Modular calculation
    template<int m, int l>
    Word_n<n>       modularAdd  (const Word_n<m>& word_n_2, const Word_n<l>& module_) const;

    template<int rank_1, int rank_2, int rank_3, int rank_4>
    Word_n<n>       montgomery  (   const Word_n<rank_1>& word_n_2,
                                    const Word_n<rank_2>& module_,
                                    const Word_n<rank_3>& r, 
                                    const Word_n<rank_4>& r_
                                ) const;


    // Overriding operators
    template<int m>
    Word_n<n + 32>  operator+   (const Word_n<m>& word_n_2) const;

    template<int m>
    Word_n<n>       operator-   (const Word_n<m>& word_n_2) const;

    template<int m>
    Word_n<2 * n>   operator*   (const Word_n<m>& word_n_2) const;

    Word_n<n>&      operator=   (std::string data);

    template<int m>
    Word_n<n>&      operator=   (const Word_n<m>& word_n_2);


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
 * Word<n+1> cast
 */
template <int n>
Word_n<2 * n> Word_n<n>::upSize() const {

    /**
     * n verification :
     * 
     * -> because it generate a result with a rank 2 * n which must respect 2 * n <= 65 536,
     * n <= 32 768
     */
    static_assert(n <= 32768, "The rank of the operand must be lower than 32 768.");


    // Result generation
    Word_n<2 * n> result;


    // Running through all data in the operand
    for (int i = 0; i < this->data.size(); i++) {

        // Copying data
        result.setBloc(this->getBloc(i), i);

    }


    // Returning result
    return result;

}


/**
 * Word<n+1> cast
 */
template <int n>
Word_n<n / 2> Word_n<n>::downSize() const {

    /**
     * n verification :
     * 
     * -> because it generate a result with a rank n / 2 which must respect n / 2 >= 64,
     * n >= 128
     */
    static_assert(n >= 128, "The rank of the operand must be greater than 128.");


    // Result generation
    Word_n<n / 2> result;


    // Running through all data in the operand
    for (int i = 0; i < result.dataSize(); i++) {

        // Copying data
        result.setBloc(this->getBloc(i), i);

    }


    // Returning result
    return result;

}


/**
 * Crop another Word<m> with m >= n
 */
template <int n>
template <int m>
void  Word_n<n>::crop(const Word_n<m>& word_n_2) {

    /**
     * n and m verification :
     * 
     * -> m must be greater than n
     */
    static_assert(n <= m,       "The rank of the second operand must be greater than the first one");


    // Getting all data possible
    for (int i = 0; i < (n / 32); i++) {
        this->data[i] = word_n_2.getBloc(i);
    }

}


/**
 * Returning the maximum value possible
 */
template <int n>
Word_n<n>  Word_n<n>::maxValue() {

    // Generating the value
    Word_n<n> max_val;


    // Running through every word unit
    for (int i = 0; i < max_val.dataSize(); i++) {

        // Maximize data
        max_val.getBloc(i).maxValue();

    }


    // Returning the value
    return max_val;

}


/**
 * Returning the maximum value possible
 */
template <int n>
Word_n<n>  Word_n<n>::nullValue() {

    // Generating the value
    Word_n<n> null_val;


    // Returning the value
    return null_val;

}


/**
 * ================================================================================================
 * Modular operation
 * ================================================================================================
 */

/**
 * Modular addition
 */
template <int n>
template <int m, int l>
Word_n<n> Word_n<n>::modularAdd(const Word_n<m>& word_n_2, const Word_n<l>& module_) const {

    /**
     * Operand verification :
     * 
     * -> the rank of all 3 operand must be equal : n = m = l
     * -> because it generate a result with a rank 2 * n which must respect 2 * n <= 65 536,
     * n <= 32 768
     * -> we considere that in A + B [N], A and B are already modulo N. And so, A and B are
     * lower than N.
     */
    static_assert(n == m,       "The rank of the three operand must be equal.");
    static_assert(n < 32768,    "The rank of the two added operand must be lower than 32 768.");


    // Verification
    if (*this >= module_ || word_n_2 >= module_) {
        throw std::out_of_range("The two added operand must be lower than the module.");
    }


    // Generating the result
    Word_n<2 * n> sum;


    // Making the actual addition
    sum = *this + word_n_2;


    // Module comparaison
    if (sum < module_.upSize()) {

        // Returning the module
        return sum.downSize();


    } else {

        // Returing the sum (downsized)
        return (sum.downSize() - module_);

    }

}


/**
 * Modular multiplication
 */
template <int n>
template<int rank_1, int rank_2, int rank_3, int rank_4>
Word_n<n> Word_n<n>::montgomery(const Word_n<rank_1>& word_n_2,
                                const Word_n<rank_2>& module_,
                                const Word_n<rank_3>& r, 
                                const Word_n<rank_4>& r_
                                ) const {

    /**
     * Operand verification :
     * 
     * -> the rank of all operand must be equal except for the R which is the rank plus one.
     * -> because there is a intermediary result, the same rules for size check is needed.
     * -> we considere that in A * B [N], A and B are already modulo N. And so, A and B are
     * lower than N.
     */
    static_assert(  n == rank_1 &&
                    n == rank_2 &&
                    n == (rank_3 - 32) &&
                    n == rank_4,            "The rank of all operand must be equal (except for the R).");
    static_assert(n < 16384,                "The rank of the two multiplied operand must be lower than 16 384.");


    // // Verification
    // if (*this >= module_ || word_n_2 >= module_) {
    //     throw std::out_of_range("The two operand multiplied must be lower than the module.");
    // }


    // Division simplification verification


    // S = A * B
    Word_n<2 * n>       _S_;
    _S_                 = *this * word_n_2;

    _S_.display(true);
    std::cout << "0x70344D18 918BA254 B873966A 466FE402 FC5B5C23 9DAC62DD CC875CDD D68DE105 E431B4AB 9FDCF0C1 8C542F84 0E8E0997 99F35A5F 0627731D 2E390FAB E2505520" << std::endl;


    // T = S * R' [R]
    Word_n<n + 32>      _T_;
    _T_.crop            (_S_ * r_.upSize());            // TODO : explain this
    _T_.setBloc         (_T_.getBloc(n + 31).getData() & 0x0FFFFFFF, n + 31);


    // M = S + T * N = S + temp
    Word_n<2 * n + 32>  _M_;
    Word_n<n + 32>      temp_mod;
    temp_mod            = module_;
    Word_n<2 * n + 32>  temp_S;
    temp_S              = _S_;
    Word_n<2 * n + 32>  temp_mul;
    temp_mul            .crop(_T_ * temp_mod);
    _M_                 .crop(temp_S + temp_mul);


    // U = M / R
    Word_n<n>           _U_;
    _U_                 .crop(_M_);


    // Result calculation
    Word_n<n>           product;
    if (_U_ > module_) {
        product         = _U_ - module_;
    } else {
        product         = _U_;
    }


    // Returning the result
    return product;

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
Word_n<n + 32> Word_n<n>::operator+(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     * -> because it generate a result with a rank n + 32 which must respect n + 32 <= 65 536
     */
    static_assert(n == m,       "The rank of the two operand must be equal.");
    static_assert(n <= 65504,   "The rank of the two operand must be lower than 65 504.");


    // Sum creation
    Word_n<n + 32> sum;


    // Running through every word units
    for (int i = 0; i < this->data.size(); i++) {

        // Adding up word units
        sum.setBloc(this->data[i] + word_n_2.getBloc(i), i);


        // Carry propagation
        sum.setBloc(sum.getBloc(i).getCarry(), i + 1);
        sum.getBloc(i).resetCarry();

    }


    // Returning the sum
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


    // Substraction creation
    Word_n<n> substraction;


    // Borrow
    uint32_t borrow = 0;


    // Running through all word_units
    for (int i = 0; i < this->data.size(); i++) {

        // Substraction calculation
        uint64_t diff = static_cast<uint64_t>(this->data[i].getData()) - 
                        static_cast<uint64_t>(word_n_2.getBloc(i).getData()) -
                        static_cast<uint64_t>(borrow);


        // In cas of underflow
        if (diff > 0xFFFFFFFF) {

            // Activating borrow
            borrow = 1;


            // To correct underflow
            diff += 0x100000000;


        } else {

            // De-activating borrow
            borrow = 0;

        }


        // Saving the substraction
        substraction.setBloc(static_cast<uint32_t>(diff), i);

    }


    // Returning the substraction
    return substraction;

}


/**
 * Overriding the multiplication :
 * 
 * 
 * 
 */
template <int n>
template <int m>
Word_n<2 * n> Word_n<n>::operator*(const Word_n<m>& word_n_2) const {

    /**
     * n and m verification :
     * 
     * -> n and m must be equal.
     * -> because it generate a result with a rank 2 * n which must respect 2 * n <= 65 536,
     * n <= 32 768
     */
    static_assert(n == m,       "The rank of the two operand must be equal.");
    static_assert(n <= 32768,  "The rank of the two operand must be lower than 32 768.");


    // Product creation
    Word_n<2 * n> product;


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


    // Returning the product
    return product;

}


/**
 * Data instanciation using '=' operator and string data
 */
template <int n>
Word_n<n>& Word_n<n>::operator=(std::string data) {

    // Data instanciation
    this->setData(data);    


    // Returning itslef
    return *this;

}


/**
 * Convertion from Word<n> to Word<m> :
 * Word<n> = Word<m>
 */
template <int n>
template <int m>
Word_n<n>& Word_n<n>::operator=(const Word_n<m>& word_n_2) {

    /**
     * n and m verification :
     * 
     * -> n must be greater than m
     */
    static_assert(n >= m,       "The rank of the first operand must be greater than the second one");


    // Reseting
    this->reset();


    // Getting all data from word_n_2
    for (int i = 0; i < (m / 32); i ++) {
        this->data[i] = word_n_2.getBloc(i);
    } 


    // Returning itslef
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


    // Running through the data, starting from the strongest digit
    int i = this->data.size() - 1;
    while (i != -1) {

        // Stop condition : a pair of bloc does not respect the inequality
        if (this->data[i] < word_n_2.getBloc(i)) {
            return false;
        }


        // Stop condition : a pair of bloc does force the inequality
        if (this->data[i] > word_n_2.getBloc(i)) {
            return true;
        }


        // Decrement
        i --;

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


    // Avoiding an exception
    if (*this == word_n_2) {
        return false;
    }


    // Running through the data, starting from the strongest digit
    int i = this->data.size() - 1;
    while (i != -1) {

        // Stop condition : a pair of bloc does not respect the inequality
        if (this->data[i] < word_n_2.getBloc(i)) {
            return false;
        }


        // Stop condition : a pair of bloc does force the inequality
        if (this->data[i] > word_n_2.getBloc(i)) {
            return true;
        }


        // Decrement
        i --;

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


    // Running through the data, starting from the strongest digit
    int i = (this->data.size() - 1);
    while (i != -1) {

        // Stop condition : a pair of bloc does not respect the inequality
        if (i >= 0 && this->data[i] > word_n_2.getBloc(i)) {
            return false;
        }


        // Stop condition : a pair of bloc does force the inequality
        if (i >= 0 && this->data[i] < word_n_2.getBloc(i)) {
            return true;
        }


        // Decrement
        i --;

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


    // Avoiding an exception
    if (*this == word_n_2) {
        return false;
    }


    // Running through the data, starting from the strongest digit
    int i = this->data.size() - 1;
    while (i != -1) {

        // Stop condition : a pair of bloc does not respect the inequality
        if (this->data[i] > word_n_2.getBloc(i)) {
            return false;
        }


        // Stop condition : a pair of bloc does force the inequality
        if (this->data[i] < word_n_2.getBloc(i)) {
            return true;
        }


        // Decrement
        i --;

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
