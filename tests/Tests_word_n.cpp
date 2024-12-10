/**
 * Test for Word_n
 * 
 * 
 * Test vector : generated using python
 * 
 * @author AdrienG
 */
#include <iostream>
#include "../include/Word_n.hpp"




// Signatures
int test_Word_n_addition();
int test_Word_n_substraction();
int test_Word_n_multiplication();




/**
 * All test execution
 */
int main() {

    // Test start
    std::cout << "Test(Word_n) : START" << std::endl;


    // Display test
    Word_n<9> word;
    std::cout << word << std::endl;
    word.display();


    // Randomizer test
    word.randomize();
    word.display();


    // Addition
    int addition = test_Word_n_addition();
    if (addition == 1) {
        std::cout << "Test(Word_n) : ADDITION -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : ADDITION -> PASSED" << std::endl;
    }


    // Substraction
    int substaction = test_Word_n_substraction();
    if (substaction == 1) {
        std::cout << "Test(Word_n) : SUBSTRACTION -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : SUBSTRACTION -> PASSED" << std::endl;
    }


    // Addition
    int multiplication = test_Word_n_multiplication();
    if (multiplication == 1) {
        std::cout << "Test(Word_n) : MULTIPLICATION -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : MULTIPLICATION -> PASSED" << std::endl;
    }


    // Program end
    if ((addition + substaction + multiplication) == 0) {
        std::cout << "Test(Word_n) : PASSED" << std::endl;
        return 0;
    }
    std::cout << "Test(Word_n) : FAILED" << std::endl;
    return 1;

}




// /**
//  * Addition tests
//  */
// int test_Word_n_addition() {

//     // Test variables
//     Word_n word_n_1 = Word_n();
//     Word_n word_n_2 = Word_n();
//     Word_n word_n_3 = Word_n();


//     /**
//      * Calculation 1 :
//      * 
//      * A = 0xF1DFD08D
//      * B = 0x5A467FBE
//      * 
//      * C = A + B = 0x1 4C26504B
//      */
//     word_n_1.setData(0xF1DFD08D);
//     word_n_2.setData(0x5A467FBE);
//     word_n_3 = word_n_1 + word_n_2;


//     // Test + reset
//     if (word_n_3 != 0x14C26504B) {return 1;}
//     word_n_3.setData(0x0);




//     /**
//      * Calculation 2 :
//      * 
//      * A = 0x5D3BCC74
//      * B = 0x674B2834
//      * 
//      * C = A + B = 0xC486F4A8
//      */
//     word_n_1.setData(0x5D3BCC74);
//     word_n_3.setData(0x674B2834);
//     word_n_3 += word_n_1;


//     // Test + reset
//     if (word_n_3 != 0xC486F4A8) {return 1;}
//     word_n_3.setData(0x0);




//     /**
//      * Calculation 3 :
//      * 
//      * A = 0x77A248B4
//      * B = 0x2657693D
//      * 
//      * C = A + B = 0x9DF9B1F1
//      */
//     word_n_1.setData(0x77A248B4);
//     word_n_2.setData(0x2657693D);
//     word_n_3 = word_n_1 + word_n_2;


//     // Test + reset
//     if (word_n_3 != 0x9DF9B1F1) {return 1;}
//     word_n_3.setData(0x0);




//     // End of test
//     return 0;

// };




// /**
//  * Substraction tests
//  */
// int test_Word_n_substraction() {

//     // Test variables
//     Word_n word_n_1 = Word_n();
//     Word_n word_n_2 = Word_n();
//     Word_n word_n_3 = Word_n();


//     /**
//      * Calculation 1 :
//      * 
//      * A = 0x94349C86
//      * B = 0x62E95794
//      * 
//      * C = A - B = 0x314B44F2
//      */
//     word_n_1.setData(0x94349C86);
//     word_n_2.setData(0x62E95794);
//     word_n_3 = word_n_1 - word_n_2;


//     // Test + reset
//     if (word_n_3 != 0x314B44F2) {return 1;}
//     word_n_3.setData(0x0);




//     /**
//      * Calculation 2 :
//      * 
//      * A = 0xBF6E8AF5
//      * B = 0x5902142E
//      * 
//      * C = A - B = 0x666C76C7
//      */
//     word_n_1.setData(0xBF6E8AF5);
//     word_n_2.setData(0x5902142E);
//     word_n_3 = word_n_1 - word_n_2;


//     // Test + reset
//     if (word_n_3 != 0x666C76C7) {return 1;}
//     word_n_3.setData(0x0);




//     /**
//      * Calculation 3 :
//      * 
//      * A = 0x9284A957
//      * B = 0x51D30D2A
//      * 
//      * C = A - B = 0x40B19C2D
//      */
//     word_n_1.setData(0x9284A957);
//     word_n_2.setData(0x51D30D2A);
//     word_n_3 = word_n_1 - word_n_2;


//     // Test + reset
//     if (word_n_3 != 0x40B19C2D) {return 1;}
//     word_n_3.setData(0x0);




//     // End of test
//     return 0;

// };




// /**
//  * Multiplication tests
//  */
// int test_Word_n_multiplication() {

//     // Test variables
//     Word_n word_n_1 = Word_n();
//     Word_n word_n_2 = Word_n();
//     Word_n word_n_3 = Word_n();


//     /**
//      * Calculation 1 :
//      * 
//      * A = 0xFEDEAB26
//      * B = 0x892B5FD5
//      * 
//      * C = A * B = 0x88905866 C629809E
//      */
//     word_n_1.setData(0xFEDEAB26);
//     word_n_2.setData(0x892B5FD5);
//     word_n_3 = word_n_1 * word_n_2;


//     // Test + reset
//     if (word_n_3 != 0x88905866C629809E) {return 1;}
//     word_n_3.setData(0x0);




//     /**
//      * Calculation 2 :
//      * 
//      * A = 0xE0F017AE
//      * B = 0x878B3C5E
//      * 
//      * C = A * B = 0x7718F3E4 7B2F79E4
//      */
//     word_n_1.setData(0xE0F017AE);
//     word_n_2.setData(0x878B3C5E);
//     word_n_3 = word_n_1 * word_n_2;


//     // Test + reset
//     if (word_n_3 != 0x7718F3E47B2F79E4) {return 1;}
//     word_n_3.setData(0x0);




//     /**
//      * Calculation 3 :
//      * 
//      * A = 0x79FAAA1A
//      * B = 0xD5B183E6
//      * 
//      * C = A + B = 0x65D224B0 1A3A215C
//      */
//     word_n_1.setData(0x79FAAA1A);
//     word_n_2.setData(0xD5B183E6);
//     word_n_3 = word_n_1 * word_n_2;


//     // Test + reset
//     if (word_n_3 != 0x65D224B01A3A215C) {return 1;}
//     word_n_3.setData(0x0);




//     // End of test
//     return 0;

// }
