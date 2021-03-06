/**
 * @file bitwise.c
 * @author Braiden Gole
 * @brief This is my first script using bitwise operators I learned a lot
 *        throught this project.
 * @version 0.1
 * @date 2020-12-27
 * @copyright Copyright (c) Braiden Gole 2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define KLENGTH 9
#define K100BYTES 100
#define KONE 1

// Function prototypes.
void binaryRepresentation(unsigned char input, const int howManyCharBits);
void displayInput(char *input);
int bitwiseIncrement(int incrementorBits);
const int doubleBitValue(int valueToDouble);

int main(void)
{   
    // #include <limits.h> has pre-defined macros that I put to use.

    // Set the constant value we are using the macro CHAR_BIT so we only set
    // a maximum value of 255 because we are dealing with an 8 bit number.

    // You can change the argument 2 of binaryRepresentation() to a higher constant
    // that way you will have values past 255, because 2^7 11111111 = 255 8 Bits ON.
    const int KVALUEUPTO255 = 255;
    binaryRepresentation(KVALUEUPTO255, CHAR_BIT);

    char userInput[K100BYTES] = {"Braiden Gole"};
    displayInput(userInput);

    int value = 100;
    printf("\nThe value doubled: [%i]", doubleBitValue(value));
    return 0;
}

/**     -- Method header comment
 *  Method          :   binaryRepresentation
 *  Description     :   Outputs the binary representation of the given decimal number.
 *  Parameters      :   unsigned char input, const int howManyCharBits
 *  Returns         :   None
 */
void binaryRepresentation(unsigned char input, const int howManyCharBits)
{   
    // The strings length.
    const char KZERO = '0';

    int bits = 0;
    int numberOfBitsInChar = howManyCharBits;

    printf("\n>>> Binary Representation of (%i): [", input);
    while (numberOfBitsInChar > 0)
    {    
        --numberOfBitsInChar;
        bits = (KZERO + (input >> numberOfBitsInChar)) & KONE;
        printf("%i", bits);
    }
    putchar(']');
}

/**     -- Method header comment
 *  Method          :   displayInput
 *  Description     :   This will display the input supplied.
 *  Parameters      :   input
 *  Returns         :   None
 */
void displayInput(char *input)
{   
    printf("\n>>> Your input is displayed below using bitwise operators.\n");
    int symbols = 0;
    int lengthOfIp = strlen(input);
    while (symbols < lengthOfIp)
    {
        printf("\t%c\n", input[symbols]);

        // BITWISE INCREMENT.
        symbols = bitwiseIncrement(symbols);
    }
}

/**     -- Method header comment
 *  Method          :   bitwiseIncrement
 *  Description     :   This will increment a integer variable using bitwise
 *                      operators.
 *  Parameters      :   incrementorBits
 *  Returns         :   incrementorBits
 */
int bitwiseIncrement(int incrementorBits)
{   
    int on = 1;
    while (incrementorBits & on)
    {   
        // Flip the bits after the furthest rightmost 0.
        incrementorBits ^= on;
        on <<= KONE;
    }
    // Flip where that rightmost 0 bit was found.
    incrementorBits ^= on;
    return incrementorBits;
}

/**     -- Function header comment
 *  FUNCTION        :   doubleBitValue
 *  DESCRIPTION     :   This function will double the value supplied
 *                      as input using bitwise operators.
 *  PARAMETERS      :   valueToDouble
 *  RETURNS         :   result
 */
const int doubleBitValue(int valueToDouble)
{
    int result = valueToDouble << KONE;
    return result;
}