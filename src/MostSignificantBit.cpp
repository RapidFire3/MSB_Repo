#include<iostream>
#include<sstream>

/*******************************************************************************
 *                          getMostSignificantBit()
 * This method is responsible for returning the index or position of the most
 * significant bit of a given integer when in the binary representation.
 * 
 * @param inputNumber   the number that the method must find the msb of.
 * @return              the most significant bit of the input number.
 * @author              Jeff Gardner
********************************************************************************/
int getMostSignificantBit(int inputNumber)
{
    //  Number of bits of the input number that must tested for the potential
    //  most significant bit.
    int bitSize = 32;

    //  Current bit index starting from most significant bit to least significant 
    //  bit (left -> right) of the input number.
    int currentIndex = 0;

    //  Index of the most significant bit.
    int msbIndex = 0; 

    if (inputNumber != 0) 
    {
        while (currentIndex < bitSize)
        {
            //  The first index that is set or not zero is the most significant bit.
            //  The current index is the MSB and will break out of while loop.
            if ((inputNumber & 0x80000000) == 0x80000000)
                break;

            //  Conduct a left shift by 1 to determine if the next index is a potential
            //  MSB.
            inputNumber <<= 1;

            currentIndex++;
        }

        //  The index or the position of the most significant bit of the input number.
        //  From least to most significant bit (right -> left)
        msbIndex = bitSize - (currentIndex + 1);
    }

    return msbIndex;
}


int main(int argc, char* argv[]) {
    if(argc < 2) 
        std::cout << "Please provide a valid Integer."<< std::endl;
    
    else 
    {
        //  Holds the string version of the integer.
        std::stringstream inArg;

        //  Put the argument onto the buffer to prepare for conversion.
        inArg.str(argv[1]);

        //  Extract the buffer contents to integer variable.
        int usrValue = 0;
        inArg >> usrValue;

        //  Clear the buffer.
        inArg.str("");

        //  Find the most significant bit if the value is not out of bounds.
        if (usrValue < INT32_MAX && usrValue > INT32_MIN )
            std::cout << getMostSignificantBit(usrValue) << std::endl;
    }
    
    return 0;
}