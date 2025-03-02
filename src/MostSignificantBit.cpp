#include <iostream>
#include <sstream>
#include <cstdint>

/*******************************************************************************
 *                          getMostSignificantBit()
 * 	
 *	This function is responsible for returning the index or position of the most
 * 	significant bit of a given integer when in the binary representation.
 * 
 * @param inputNumber   the 64 bit signed integer that the function must locate 
 *						the MSB for.
 * @return              the most significant bit of the input number.
 * @author              Jeff Gardner
********************************************************************************/
int getMostSignificantBit( int64_t inputNumber )
{
    //  Number of bits of the input number that must tested for the potential
    //  most significant bit.
    int bitSize{ 64 };

    //  Current bit index starting from most significant bit to least significant 
    //  bit ( left -> right ) of the input number.
    int currentIndex{ 0 };

    //  Index of the most significant bit.
    int msbIndex{ 0 };


    if ( inputNumber != 0 ) 
    {
        while ( currentIndex < bitSize ) 
		{
            //  The first index that is set or not zero is the most significant bit.
            //  The current index is the MSB and will break out of while loop.
            if (( inputNumber & 0x8000000000000000 ) == 0x8000000000000000 )
            	break;

            //  Conduct a left shift by 1 to determine if the next index is a potential
            //  MSB.
            inputNumber <<= 1;
			
            currentIndex++;
        }

        //  The index or the position of the most significant bit of the input number.
        //  From least to most significant bit ( right -> left )
        msbIndex = bitSize - ( currentIndex + 1 );
    }

    return msbIndex;
}


int main( int argc, char* argv[] ) 
{
	//	Ensure that a value was provided with the file name.
    if( argc < 2 ) 
	{
        std::cout << "Please provide a valid Integer. \n";
    }

    else 
    {
        //	Will contain the integer argument passed to the program as a string.
        std::stringstream inArg;

        //  Place the argument, which should be the desired integer,  onto the 
		//	buffer to prepare for string to integer conversion.
        inArg.str( argv[1] );

        //  Extract the stringstream buffer contents to an integer type.
        int64_t valueToProcess{};
        inArg >> valueToProcess;

		//  Clear the buffer.
        inArg.str( "" );

        //	Locate the position of the Most Significant Bit ( MSB ) of a 32-bit 
		//	value passed to the program.
		if ( valueToProcess <= INT64_MAX && valueToProcess >= INT64_MIN )
        {   
			std::cout << getMostSignificantBit( valueToProcess ) << '\n';
		}
    }
    
    return 0;
}
