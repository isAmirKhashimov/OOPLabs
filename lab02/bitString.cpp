#include "bitString.h"
#include <iostream>
#include <bitset>
#include <climits>

BitString operator^(const BitString bits1, const BitString bits2)
{
    return BitString(bits1.left ^ bits2.left, bits1.right ^ bits2.right);
}

BitString operator&(const BitString bits1, const BitString bits2)
{
    return BitString(bits1.left & bits2.left, bits1.right & bits2.right);
}

BitString operator|(const BitString bits1, const BitString bits2)
{
    return BitString(bits1.left | bits2.left, bits1.right | bits2.right);
}

BitString operator~(const BitString bits1)
{
    return BitString(~bits1.left, ~bits1.right);
}


BitString operator<<(const BitString bits, int count)
{
    return BitString((bits.left << count) | (bits.right >> (64 - count)), bits.right << count);
}

BitString operator>>(const BitString bits, int count)
{
    return BitString(bits.left >> count, (bits.right >> count) | (bits.left << (64 - count)));
}

bool operator<(BitString bits1, BitString bits2)
{
    return bits1.CountOnes() < bits2.CountOnes();
}

bool operator>(BitString bits1, BitString bits2)
{
    return bits1.CountOnes() > bits2.CountOnes();
}

bool operator==(BitString bits1, BitString bits2)
{
    return bits1.CountOnes() == bits2.CountOnes();
}

bool operator!= (BitString bits1, BitString bits2)
{
    return bits1.CountOnes() != bits2.CountOnes();
}

BitString::BitString(ull left, ull right)
{
    this->left = left;
    this->right = right;
}

void BitString::Print()
{
    std::cout << std::bitset<sizeof(left)* CHAR_BIT>(left) << std::bitset<sizeof(left)* CHAR_BIT>(right) << " " << "Count of ones: " <<  CountOnes() << std::endl;
}

int BitString::CountOnes()
{
    ull it = 1;
    int count = 0;
    for (int i = 0; i < 64; i++)
    {
        count += (left & it) ? 1: 0;
        count += (right & it) ? 1 : 0;
        it <<= 1;
    }
    return count;
}
