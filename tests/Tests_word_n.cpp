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
int test_Word_n_comparator();
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
    std::cout << "Test(Word_n) : RANDOMIZE -> \n";
    word.display();
    std::cout << "\n\n" << std::endl;


    // Data size test
    if (word.dataSize() != 4) {
        test += 1;
        std::cout << "Test(Word_n) : DATA SIZE                 -> FAILED";
    } else {
        std::cout << "Test(Word_n) : DATA SIZE                 -> PASSED\n";
    }


    // Binary size test
    if (word.binarySize() != 128) {
        test += 1;
        std::cout << "Test(Word_n) : BINARY SIZE               -> FAILED {=" << word.binarySize() << "}\n";
    } else {
        std::cout << "Test(Word_n) : BINARY SIZE               -> PASSED\n";
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
        std::cout << "Test(Word_n) : RESET                     -> FAILED\n";
    } else {
        std::cout << "Test(Word_n) : RESET                     -> PASSED\n";
    }


    // String setter test
    word.setData("0xF8E0CB F98A87BC 3741903B 75438F48");
    if (word.getBloc(3) != 0x00F8E0CB || word.getBloc(2) != 0xF98A87BC || word.getBloc(1) != 0x3741903B || word.getBloc(0) != 0x75438F48) {
        test += 1;
        std::cout << "Test(Word_n) : STRING SETTER             -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : STRING SETTER             -> PASSED" << std::endl;
    }


    // Data instanciation with = string test
    word = "0xF8E0CB F98A87BC 3741903B 75438F48";
    if (word.getBloc(3) != 0x00F8E0CB || word.getBloc(2) != 0xF98A87BC || word.getBloc(1) != 0x3741903B || word.getBloc(0) != 0x75438F48) {
        test += 1;
        std::cout << "Test(Word_n) : OP (VAR = STRING)         -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : OP (VAR = STRING)         -> PASSED" << std::endl;
    }


    // Comparators
    int comparator = test_Word_n_addition();
    if (comparator == 1) {
        std::cout << "Test(Word_n) : COMPARATOR                -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : COMPARATOR                -> PASSED" << std::endl;
    }
    test += comparator;


    // Addition
    int addition = test_Word_n_addition();
    if (addition == 1) {
        std::cout << "Test(Word_n) : ADDITION                  -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : ADDITION                  -> PASSED" << std::endl;
    }
    test += addition;


    // Substraction
    int substaction = test_Word_n_substraction();
    if (substaction == 1) {
        std::cout << "Test(Word_n) : SUBSTRACTION              -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : SUBSTRACTION              -> PASSED" << std::endl;
    }
    test += substaction;


    // Addition
    int multiplication = test_Word_n_multiplication();
    if (multiplication == 1) {
        std::cout << "Test(Word_n) : MULTIPLICATION            -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n) : MULTIPLICATION            -> PASSED" << std::endl;
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
 * Comparator tests
 */
int test_Word_n_comparator() {

    // Test variables
    Word_n<8> word_n_1;
    Word_n<8> word_n_2;




    /**
     * Equality test between one word_n and a string
     */
    word_n_1 = "0x61E6F2B3 8959347E 6977D9B4 9F5B3B61 E403EF5B 8E595957 4F4B29D2 9543AA3B";
    if ((word_n_1 == "0x61E6F2B3 8959347E 6977D9B4 9F5B3B61 E403EF5B 8E595957 4F4B29D2 9543AA3B") != true) {
        return 1;
    }
    if ((word_n_1 == "0xAD7F3F6F 5CDFB656 AF10103C 7DFE9C43 2B2D2703 F6C9CC17 32E1466D 04B5D524") != true) {
        return 1;
    }




    /**
     * Equality test between two word_n
     */
    word_n_2 = "0x61E6F2B3 8959347E 6977D9B4 9F5B3B61 E403EF5B 8E595957 4F4B29D2 9543AA3B";
    if ((word_n_1 == word_n_2) != true) {
        return 1;
    }
    word_n_2 = "0xAD7F3F6F 5CDFB656 AF10103C 7DFE9C43 2B2D2703 F6C9CC17 32E1466D 04B5D524";
    if ((word_n_1 != word_n_2) != true) {
        return 1;
    }




    /**
     * Differential test between two word_n_unitary
     */
    word_n_1 = "0xAD7F3F6F 5CDFB656 AF10103C 7DFE9C43 2B2D2703 F6C9CC17 32E1466D 04B5D524";
    word_n_2 = "0xAD7F3F6F 5CDFB656 AF10103C 7DFE9C43 2B2D2703 F6C9CC17 32E1466D 04B5D524";
    if ((word_n_1 >= word_n_2) != true) {
        return 1;
    }
    if ((word_n_1 <= word_n_2) != true) {
        return 1;
    }
    word_n_2 = "0x61E6F2B3 8959347E 6977D9B4 9F5B3B61 E403EF5B 8E595957 4F4B29D2 9543AA3B";
    if ((word_n_1 >= word_n_2) != true) {
        return 1;
    }
    if ((word_n_1 > word_n_2) != true) {
        return 1;
    }
    word_n_1 = "0x61E6F2B3 8959347E 6977D9B4 9F5B3B61 E403EF5B 8E595957 4F4B29D2 9543AA3B";
    word_n_2 = "0xAD7F3F6F 5CDFB656 AF10103C 7DFE9C43 2B2D2703 F6C9CC17 32E1466D 04B5D524";
    if ((word_n_1 <= word_n_2) != true) {
        return 1;
    }
    if ((word_n_1 < word_n_2) != true) {
        return 1;
    }




    // End of the test
    return 0;

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

    // Test variables
    Word_n<8> word_n_1;
    Word_n<8> word_n_2;
    Word_n<8> word_n_3;


    /**
     * Calculation 1 :
     * 
     * A = 0x7C47230A AFC0761D C5A4F9EA 06564647 5DDB6827 9B666E95 017B3963 FF7E2A74
     * B = 0x770A28A6 1EF7E4BB 16E88202 33AC0320 7904EFD2 E04006C1 02D2FDDE FF2D7B62
     * 
     * C = A - B = 0x053CFA64 90C89162 AEBC77E7 D2AA4326 E4D67854 BB2667D3 FEA83B85 0050AF12
     */
    word_n_1 = "0x7C47230A AFC0761D C5A4F9EA 06564647 5DDB6827 9B666E95 017B3963 FF7E2A74";
    word_n_2 = "0x770A28A6 1EF7E4BB 16E88202 33AC0320 7904EFD2 E04006C1 02D2FDDE FF2D7B62";
    word_n_3 = word_n_1 - word_n_2;


    // Test + reset
    if (word_n_3 != "0x053CFA64 90C89162 AEBC77E7 D2AA4326 E4D67854 BB2667D3 FEA83B85 0050AF12") {return 1;}
    word_n_3.setData("0x0");




    /**
     * Calculation 2 :
     * 
     * A = 0x22D902CF F3EC9A53 5C079453 00FF4E2B 360241A9 FE06B55C 791E143E 8A98FBA4
     * B = 0x0D438A4F CABF8E2A F69D5033 8653C2EE C02A7543 28DFF42A B6AF0C1A BCCC5C6C
     * 
     * C = A + B = 0x15957880 292D0C28 656A441F 7AAB8B3C 75D7CC66 D526C131 C26F0823 CDCC9F38
     */
    word_n_1 = "0x22D902CF F3EC9A53 5C079453 00FF4E2B 360241A9 FE06B55C 791E143E 8A98FBA4";
    word_n_2 = "0x0D438A4F CABF8E2A F69D5033 8653C2EE C02A7543 28DFF42A B6AF0C1A BCCC5C6C";
    word_n_3 = word_n_1 - word_n_2;


    // Test + reset
    if (word_n_3 != "0x15957880 292D0C28 656A441F 7AAB8B3C 75D7CC66 D526C131 C26F0823 CDCC9F38") {return 1;}
    word_n_3.setData("0x0");




    /**
     * Calculation 3 :
     * 
     * A = 0x8464EED0 464B4E87 EC0413C7 905EF760 45FE01D0 6AF5F53F 7D309958 260184F9
     * B = 0x1AAAC750 13BEDF64 85E8355F FE9C5D33 C342A880 EE38350C 01F0B92A 2A10261C
     * 
     * C = A + B = 0x9DF9B1F1
     */
    word_n_1 = "0x8464EED0 464B4E87 EC0413C7 905EF760 45FE01D0 6AF5F53F 7D309958 260184F9";
    word_n_2 = "0x1AAAC750 13BEDF64 85E8355F FE9C5D33 C342A880 EE38350C 01F0B92A 2A10261C";
    word_n_3 = word_n_1 - word_n_2;


    // Test + reset
    if (word_n_3 != "0x69BA2780 328C6F23 661BDE67 91C29A2C 82BB594F 7CBDC033 7B3FE02D FBF15EDD") {return 1;}
    word_n_3.setData("0x0");




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


    // Test + reset
    if (word_n_3 != "0x2E188743 85FEF33B 818914AC A75A77A0 4F8A84B6 40BB74D8 AA831B2B 951A0403 F4F3C6C6 E05DEA94 EF135ACA 0DE443E9 4C6E500C 9A3C812B 3D25285D 8D9F212F") {return 1;}
    word_n_3.setData("0x0");




    /**
     * Calculation 2 :
     * 
     * A = 0x3993840D 33716675 585F7949 D3FCF699 8514D7B2 4E7ADB9F 6322B260 7DBCF948
     * B = 0x9965D1B2 2E363CCE 8332A437 884276EA D4E97934 B0550770 4D568B94 4CE43894
     * 
     * C = A * B = 0x22801048 7EB95EAC 26CC6D39 93F664F4 EDB41A27 0C55F476 93E0604C B956E604 2EAF7C20 DB8F65F4 3239C1B1 FC6FBA5C 9741568E B6000DB5 1D228739 6BE7DDA0
     */
    word_n_1 = "0x3993840D 33716675 585F7949 D3FCF699 8514D7B2 4E7ADB9F 6322B260 7DBCF948";
    word_n_2 = "0x9965D1B2 2E363CCE 8332A437 884276EA D4E97934 B0550770 4D568B94 4CE43894";
    word_n_3 = word_n_1 * word_n_2;


    // Test + reset
    if (word_n_3 != "0x22801048 7EB95EAC 26CC6D39 93F664F4 EDB41A27 0C55F476 93E0604C B956E604 2EAF7C20 DB8F65F4 3239C1B1 FC6FBA5C 9741568E B6000DB5 1D228739 6BE7DDA0") {return 1;}
    word_n_3.setData("0x0");




    /**
     * Calculation 3 :
     * 
     * A = 0x1F3E2484 F66FDEFC 351D21DD FABECA01 81FC891E BCC4C858 8B9E478F C8A5C4CB
     * B = 0x9A058764 CC8C258C 092C6414 B0F1219D 85C7BFC8 98B78AF5 49E29C30 89654447
     * 
     * C = A * B = 0x12CC0EB4 C5571DE3 54A45FD9 EB4DD923 401D1FC3 D3A605EE 5096F47B DAA51803 D60C8A3A 571C5E07 23A7D1B2 125171DF 72ADF20B 73B9145A 333983F3 F556804D
     */
    word_n_1 = "0x1F3E2484 F66FDEFC 351D21DD FABECA01 81FC891E BCC4C858 8B9E478F C8A5C4CB";
    word_n_2 = "0x9A058764 CC8C258C 092C6414 B0F1219D 85C7BFC8 98B78AF5 49E29C30 89654447";
    word_n_3 = word_n_1 * word_n_2;


    // Test + reset
    if (word_n_3 != "0x12CC0EB4 C5571DE3 54A45FD9 EB4DD923 401D1FC3 D3A605EE 5096F47B DAA51803 D60C8A3A 571C5E07 23A7D1B2 125171DF 72ADF20B 73B9145A 333983F3 F556804D") {return 1;}
    word_n_3.setData("0x0");




    // End of test
    return 0;

}
