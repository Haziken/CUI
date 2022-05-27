#include <iostream>
#include <bitset>
typedef unsigned int u32;
#include <iomanip>
int main()
{
	bool b = true;
	unsigned int x = 0b1000;
	int m = 0x05;
	//x = (x | ((u32)m * b)) & ((((u32)m * b) | ~(u32)m));
	//x = ((u32)m * b | (x & ~(u32)m));
	//x = !b * (x ^ (x & (~((u32)b) & m))) + (x | (b * m)) * b;
	std::cout << std::bitset<8>(x);
	return 0;
}