#pragma once
#define ull unsigned long long
class BitString
{
private:
	ull left;
	ull right;

public:
	BitString(ull left, ull right);
	void Print();
	int CountOnes();
	friend BitString operator ^ (const BitString left, const BitString right);
	friend BitString operator & (const BitString left, const BitString right);
	friend BitString operator | (const BitString left, const BitString right);
	friend BitString operator ~ (const BitString bits);
	friend BitString operator << (const BitString bits, int count);
	friend BitString operator >> (const BitString left, int count);
	friend bool operator < (BitString bits1, BitString bits2);
	friend bool operator > (BitString bits1, BitString bits2);
	friend bool operator == (BitString bits1, BitString bits2);
	friend bool operator != (BitString bits1, BitString bits2);
};

