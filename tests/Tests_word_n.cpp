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
    std::cout << "Test(Word_n) : Cout -> \n" << word << std::endl;
    std::cout << "\n\n" << std::endl;
    std::cout << "Test(Word_n) : DISPLAY -> \n";
    word.display();
    std::cout << "\n\n" << std::endl;


    // Randomizer test
    word.randomize();
    std::cout << "Test(Word_n_unitary) : RANDOMIZE -> \n";
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
        std::cout << "Test(Word_n) : OP (VAR = STRING) -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : OP (VAR = STRING) -> PASSED" << std::endl;
    }


    // Data comparaison with another word
    Word_n<7> word_2;
    word_2 = "0xF8E0CB F98A87BC 3741903B 75438F48";
    if ((word == word_2) != true) {
        test += 1;
        std::cout << "Test(Word_n) : OP (VAR1 == VAR2) -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : OP (VAR1 == VAR2) -> PASSED" << std::endl;
    }


    // Data comparaison with a string
    if ((word == "0xF8E0CB F98A87BC 3741903B 75438F48") != true) {
        test += 1;
        std::cout << "Test(Word_n) : OP (VAR == STRING) -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : OP (VAR == STRING) -> PASSED" << std::endl;
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
    word_n_2 = "0x59891946 1E9BA176 7F9AC415 F266E080 924D43A7 2E37625F DBD3A21E ED6A31E7";
    word_n_3 = word_n_1 + word_n_2;


    // Test + reset
    if (word_n_3 != "0x1 21249B76 CE9F8DED ACA54389 E379CEB2 E47C24BD A0BCAF9B 8F79B9FF AA1AD15A") {return 1;}
    word_n_3.setData("0x0");




    /**
     * Calculation 2 :
     * 
     * A = 0x7DA49986 8F87436E F2E9AC35 5B49EF0E FCC67F14 0560010C 3C031B56 090EAE11
     * B = 0x9A1701CE 2D5399F2 AB5F87D2 71990286 E0EDA851 59380224 B2DDF3FE 4D69F47B
     * 
     * C = A + B = 0x1 17BB9B54 BCDADD61 9E493407 CCE2F195 DDB42765 5E980330 EEE10F54 5678A28C
     */
    word_n_1 = "0x7DA49986 8F87436E F2E9AC35 5B49EF0E FCC67F14 0560010C 3C031B56 090EAE11";
    word_n_2 = "0x9A1701CE 2D5399F2 AB5F87D2 71990286 E0EDA851 59380224 B2DDF3FE 4D69F47B";
    word_n_3 = word_n_1 + word_n_2;


    // Test + reset
    if (word_n_3 != "0x1 17BB9B54 BCDADD61 9E493407 CCE2F195 DDB42765 5E980330 EEE10F54 5678A28C") {return 1;}
    word_n_3.setData("0x0");




    /**
     * Calculation 3 :
     * 
     * A = 0xA0305F2B 441C96C4 A3CCE52F 0024B92C 01D09505 63321E10 A5445033 B692778C
     * B = 0xDF262EFA 7CBB63EF C8EE87D2 9ED98DF2 342FBA47 A7AD2C97 56EB5AE8 1F1E6E5A
     * 
     * C = A + B = 0x9DF9B1F1
     */
    word_n_1 = "0xA0305F2B 441C96C4 A3CCE52F 0024B92C 01D09505 63321E10 A5445033 B692778C";
    word_n_2 = "0xDF262EFA 7CBB63EF C8EE87D2 9ED98DF2 342FBA47 A7AD2C97 56EB5AE8 1F1E6E5A";
    word_n_3 = word_n_1 + word_n_2;


    // Test + reset
    if (word_n_3 != "0x1 7F568E25 C0D7FAB4 6CBB6D01 9EFE471E 36004F4D 0ADF4AA7 FC2FAB1B D5B0E5E6") {return 1;}
    word_n_3.setData("0x0");




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

    // Test variables
    Word_n<8> word_n_1;
    Word_n<8> word_n_2;
    Word_n<9> word_n_3;


    /**
     * Calculation 1 :
     * 
     * A = 0x41BF6B42 08186F48 557CE4D8 D4C4DE86 2F4F63AB E878EDA0 9922F792 23E6C9E5
     * B = 0xB37B5E99 ECD2E32B 0E3818E2 4D5F8A83 A572ECCA 3ACA9A2A 85A3EFF0 331D7D83
     * 
     * C = A * B = 0x1 21249B76 CE9F8DED ACA54389 E379CEB2 E47C24BD A0BCAF9B 8F79B9FF AA1AD15A
     */
    word_n_1 = "0x41BF6B42 08186F48 557CE4D8 D4C4DE86 2F4F63AB E878EDA0 9922F792 23E6C9E5";
    word_n_2 = "0xB37B5E99 ECD2E32B 0E3818E2 4D5F8A83 A572ECCA 3ACA9A2A 85A3EFF0 331D7D83";
    word_n_3 = word_n_1 * word_n_2;


    word_n_3.display(true);
    std::cout << "0x2E188743 85FEF33B 818914AC A75A77A0 4F8A84B6 40BB74D8 AA831B2B 951A0403 F4F3C6C6 E05DEA94 EF135ACA 0DE443E9 4C6E500C 9A3C812B 3D25285D 8D9F212F" << std::endl;


    // Test + reset
    if (word_n_3 != "0x2E188743 85FEF33B 818914AC A75A77A0 4F8A84B6 40BB74D8 AA831B2B 951A0403 F4F3C6C6 E05DEA94 EF135ACA 0DE443E9 4C6E500C 9A3C812B 3D25285D 8D9F212F") {return 1;}
    word_n_3.setData("0x0");




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
