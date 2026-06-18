/**
 * file: Bitwise_Op.c
 * description: Various Bit wise operarions.
 */


#include <stdio.h>

// Data type
typedef unsigned int UINT32;
typedef unsigned char UINT8;
//Bitwise operations

UINT32 setBit(UINT32 number, UINT8 bitop)
{
    // Prevent shifting past the 32-bit boundary
    if (bitop >= 32) {
        return number; // Return unchanged, or handle error
    }
    // Create a mask by shifting 1U to the left by 'bitop' positions.
    // Use bitwise OR (|) to force that specific bit to 1.
    return (number | (1U << bitop));
}
UINT32 clearBit(UINT32 number, UINT8 bitop)
{
    // Safety check: Ensure the bit position fits within the 32-bit boundary.
    if (bitop >= 32) 
    {
        return number; 
    }

    // 1U << bitop: Creates a mask with a 1 at the target bit position.
    // ~(mask): Bitwise NOT inverts the mask (target bit becomes 0, all other bits become 1).
    // number & inverted_mask: Bitwise AND forces the target bit to 0 and preserves all other bits.
    return (number & ~(1U << bitop));
}
UINT32 toggleBit(UINT32 number, UINT8 bitop)
{
    // Safety check: Prevent undefined shifting behavior outside the 32-bit range.
    if (bitop >= 32) 
    {
        return number; 
    }

    // 1U << bitop: Shifts the value 1 to the target bit position.
    // number ^ mask: Bitwise XOR flips the target bit's state (0 becomes 1, 1 becomes 0).
    return (number ^ (1U << bitop));
}
UINT8 readBit(UINT32 number, UINT8 bitop)
{
    // Safety check: Out-of-bounds positions safely default to returning 0.
    if (bitop >= 32) 
    {
        return 0; 
    }

    // number >> bitop: Shifts the target bit all the way to the rightmost position (position 0).
    // & 1U: Bitwise AND clears out all other bits, isolating and returning just the target bit.
    return (UINT8)((number >> bitop) & 1U);
}
UINT32 shiftLeft(UINT32 number, UINT8 shift)
{
    // Safety check: Prevent shifting out of bounds (32 bits or more)
    if (shift >= 32) 
    {
        return 0; 
    }

    // << operator moves bits left. Vacant spots on the right are filled with 0.
    return (number << shift);
}
UINT32 shiftRight(UINT32 number, UINT8 shift)
{
    // Safety check: Prevent shifting out of bounds
    if (shift >= 32) 
    {
        return 0; 
    }

    // >> operator moves bits right. Vacant spots on the left are filled with 0.
    return (number >> shift);
}
UINT32 invertAllBits(UINT32 number)
{
    // The ~ operator flips all bits across the entire 32-bit variable at once.
    return (~number);
}
UINT8 isPowerOfTwo(UINT32 number)
{
    // 0 is not a power of 2, so handle it first.
    if (number == 0) 
    {
        return 0; 
    }

    // A power of 2 ANDed with (itself - 1) will always equal 0.
    // Example for 8: (00001000 & 00000111) equals 00000000.
    if ((number & (number - 1)) == 0) 
    {
        return 1; // It is a power of 2
    }
    
    return 0; // It is not a power of 2
}
int main(void)
{

    UINT32 num =0xfe04;
    UINT8 bit=0;
    printf("Set Bit %u in num:0x%08x isand result is:0x%08x\n",bit,num,setBit(num,bit));






    return 0;



}