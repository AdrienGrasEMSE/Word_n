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

    // Test variable
    int test = 0;


    // Test start
    std::cout << "Test(Word_n) : START" << std::endl;
    std::cout << "\n\n" << std::endl;


    // Display test
    Word_n<7> word;
    std::cout << "Test(Word_n) : Cout               -> \n" << word << std::endl;
    std::cout << "\n\n" << std::endl;
    std::cout << "Test(Word_n) : DISPLAY            -> \n";
    word.display();
    std::cout << "\n\n" << std::endl;


    // Randomizer test
    word.randomize();
    std::cout << "Test(Word_n_unitary) : RANDOMIZE          -> \n";
    word.display();
    std::cout << "\n\n" << std::endl;


    // Data size test
    if (word.dataSize() != 4) {
        test += 1;
        std::cout << "Test(Word_n) : DATA SIZE          -> FAILED";
    } else {
        std::cout << "Test(Word_n) : DATA SIZE          -> PASSED\n";
    }


    // Binary size test
    if (word.binarySize() != 128) {
        test += 1;
        std::cout << "Test(Word_n) : BINARY SIZE          -> FAILED {=" << word.binarySize() << "}\n";
    } else {
        std::cout << "Test(Word_n) : BINARY SIZE          -> PASSED\n";
    }


    // Reset test
    word.reset();
    int reset = 0;
    for (int i = 0; i < word.dataSize(); i ++) {
        if (word.getBloc(i) != 0x0) {
            reset = 1;
            break;
        }
    }
    if (reset != 0) {
        test += 1;
        std::cout << "Test(Word_n) : RESET          -> FAILED\n";
    } else {
        std::cout << "Test(Word_n) : RESET          -> PASSED\n";
    }


    // String setter test
    word.setData("0xF8E0CB F98A87BC 3741903B 75438F48");
    if (word.getBloc(3) != 0x00F8E0CB || word.getBloc(2) != 0xF98A87BC || word.getBloc(1) != 0x3741903B || word.getBloc(0) != 0x75438F48) {
        test += 1;
        std::cout << "Test(Word_n) : STRING SETTER -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : STRING SETTER -> PASSED" << std::endl;
    }


    // Data instanciation with = string test
    word = "0xF8E0CB F98A87BC 3741903B 75438F48";
    if (word.getBloc(3) != 0x00F8E0CB || word.getBloc(2) != 0xF98A87BC || word.getBloc(1) != 0x3741903B || word.getBloc(0) != 0x75438F48) {
        test += 1;
        std::cout << "Test(Word_n) : STRING SETTER -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : STRING SETTER -> PASSED" << std::endl;
    }


    // Addition
    int addition = test_Word_n_addition();
    if (addition == 1) {
        std::cout << "Test(Word_n) : ADDITION -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : ADDITION -> PASSED" << std::endl;
    }
    test += addition;


    // Substraction
    int substaction = test_Word_n_substraction();
    if (substaction == 1) {
        std::cout << "Test(Word_n) : SUBSTRACTION -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : SUBSTRACTION -> PASSED" << std::endl;
    }
    test += substaction;


    // Addition
    int multiplication = test_Word_n_multiplication();
    if (multiplication == 1) {
        std::cout << "Test(Word_n) : MULTIPLICATION -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : MULTIPLICATION -> PASSED" << std::endl;
    }
    test += multiplication;


    // Program end
    std::cout << "\n\n" << std::endl;
    if (test == 0) {
        std::cout << "Test(Word_n) : PASSED" << std::endl;
        return 0;
    }
    std::cout << "Test(Word_n) : FAILED" << std::endl;
    return 1;

}




/**
 * Addition tests
 */
int test_Word_n_addition() {

    // Test variables
    Word_n<8> word_n_1;
    Word_n<8> word_n_2;
    Word_n<9> word_n_3;


    /**
     * Calculation 1 :
     * 
     * A = 0xC79B8230 B003EC77 2D0A7F73 F112EE32 522EE116 72854D3B B3A617E0 BCB09F73
     * B = 0x59891946 1E9BA176 7F9AC415 F266E080 924D43A7 2E37625F DBD3A21E ED6A31E7
     * 
     * C = A + B = 0x1 21249B76 CE9F8DED ACA54389 E379CEB2 E47C24BD A0BCAF9B 8F79B9FF AA1AD15A
     */
    word_n_1 = "0xC79B8230 B003EC77 2D0A7F73 F112EE32 522EE116 72854D3B B3A617E0 BCB09F73";
    word_n_2.setData("0x59891946 1E9BA176 7F9AC415 F266E080 924D43A7 2E37625F DBD3A21E ED6A31E7");
    word_n_3 = word_n_1 + word_n_2;


    // Test + reset
    // if (word_n_3 != 0x14C26504B) {return 1;}
    // word_n_3.setData(0x0);




    // /**
    //  * Calculation 2 :
    //  * 
    //  * A = 0x5D3BCC74
    //  * B = 0x674B2834
    //  * 
    //  * C = A + B = 0xC486F4A8
    //  */
    // word_n_1.setData(0x5D3BCC74);
    // word_n_3.setData(0x674B2834);
    // word_n_3 += word_n_1;


    // // Test + reset
    // if (word_n_3 != 0xC486F4A8) {return 1;}
    // word_n_3.setData(0x0);




    // /**
    //  * Calculation 3 :
    //  * 
    //  * A = 0x77A248B4
    //  * B = 0x2657693D
    //  * 
    //  * C = A + B = 0x9DF9B1F1
    //  */
    // word_n_1.setData(0x77A248B4);
    // word_n_2.setData(0x2657693D);
    // word_n_3 = word_n_1 + word_n_2;


    // // Test + reset
    // if (word_n_3 != 0x9DF9B1F1) {return 1;}
    // word_n_3.setData(0x0);




    // End of test
    return 0;

};




/**
 * Substraction tests
 */
int test_Word_n_substraction() {

    // // Test variables
    // Word_n word_n_1 = Word_n();
    // Word_n word_n_2 = Word_n();
    // Word_n word_n_3 = Word_n();


    // /**
    //  * Calculation 1 :
    //  * 
    //  * A = 0x94349C86
    //  * B = 0x62E95794
    //  * 
    //  * C = A - B = 0x314B44F2
    //  */
    // word_n_1.setData(0x94349C86);
    // word_n_2.setData(0x62E95794);
    // word_n_3 = word_n_1 - word_n_2;


    // // Test + reset
    // if (word_n_3 != 0x314B44F2) {return 1;}
    // word_n_3.setData(0x0);




    // /**
    //  * Calculation 2 :
    //  * 
    //  * A = 0xBF6E8AF5
    //  * B = 0x5902142E
    //  * 
    //  * C = A - B = 0x666C76C7
    //  */
    // word_n_1.setData(0xBF6E8AF5);
    // word_n_2.setData(0x5902142E);
    // word_n_3 = word_n_1 - word_n_2;


    // // Test + reset
    // if (word_n_3 != 0x666C76C7) {return 1;}
    // word_n_3.setData(0x0);




    // /**
    //  * Calculation 3 :
    //  * 
    //  * A = 0x9284A957
    //  * B = 0x51D30D2A
    //  * 
    //  * C = A - B = 0x40B19C2D
    //  */
    // word_n_1.setData(0x9284A957);
    // word_n_2.setData(0x51D30D2A);
    // word_n_3 = word_n_1 - word_n_2;


    // // Test + reset
    // if (word_n_3 != 0x40B19C2D) {return 1;}
    // word_n_3.setData(0x0);




    // End of test
    return 0;

};




/**
 * Multiplication tests
 */
int test_Word_n_multiplication() {

    // // Test variables
    // Word_n word_n_1 = Word_n();
    // Word_n word_n_2 = Word_n();
    // Word_n word_n_3 = Word_n();


    // /**
    //  * Calculation 1 :
    //  * 
    //  * A = 0xFEDEAB26
    //  * B = 0x892B5FD5
    //  * 
    //  * C = A * B = 0x88905866 C629809E
    //  */
    // word_n_1.setData(0xFEDEAB26);
    // word_n_2.setData(0x892B5FD5);
    // word_n_3 = word_n_1 * word_n_2;


    // // Test + reset
    // if (word_n_3 != 0x88905866C629809E) {return 1;}
    // word_n_3.setData(0x0);




    // /**
    //  * Calculation 2 :
    //  * 
    //  * A = 0xE0F017AE
    //  * B = 0x878B3C5E
    //  * 
    //  * C = A * B = 0x7718F3E4 7B2F79E4
    //  */
    // word_n_1.setData(0xE0F017AE);
    // word_n_2.setData(0x878B3C5E);
    // word_n_3 = word_n_1 * word_n_2;


    // // Test + reset
    // if (word_n_3 != 0x7718F3E47B2F79E4) {return 1;}
    // word_n_3.setData(0x0);




    // /**
    //  * Calculation 3 :
    //  * 
    //  * A = 0x79FAAA1A
    //  * B = 0xD5B183E6
    //  * 
    //  * C = A + B = 0x65D224B0 1A3A215C
    //  */
    // word_n_1.setData(0x79FAAA1A);
    // word_n_2.setData(0xD5B183E6);
    // word_n_3 = word_n_1 * word_n_2;


    // // Test + reset
    // if (word_n_3 != 0x65D224B01A3A215C) {return 1;}
    // word_n_3.setData(0x0);




    // End of test
    return 0;

}
