#include <iostream>
#include <cstdint>
#include <cstdlib>

#include "main.hpp"

int main(int argc, char** argv) {

	std::cout.flags( std::ios::showbase );
	std::cout << "Size of long: " << sizeof(uint64_t) << std::endl;
	uint64_t testValue = 0;
	uint16_t smallerValue1 = 1024;
	uint16_t smallerValue2 = 4096;
	uint16_t smallerValue3 = 2048;
	uint16_t smallerValue4 = 512;

	testValue = smallerValue1;

	//"make room" for the next ushort
	testValue = testValue << 16;
	testValue ^= smallerValue2;

	testValue = testValue << 16;
	testValue ^= smallerValue3;

	testValue = testValue << 16;
	testValue ^= smallerValue4;

	std::cout << "Value in hex: " << std::hex << testValue << std::endl;

	//should truncate the high 32-bits of data
	uint32_t low32Bits = (uint32_t)testValue;

	uint32_t high32Bits = ((testValue & 0xFFFFFFFF00000000) >> 32);	

	uint16_t high1_16 = ((testValue & 0xFFFF000000000000) >> 48);
	uint16_t high2_16 = ((testValue & 0x0000FFFF00000000) >> 32);
	uint16_t low1_16  = ((testValue & 0x00000000FFFF0000) >> 16);
	uint16_t low2_16  =  (testValue & 0x000000000000FFFF);


	std::cout << "MSB32: " << std::hex << high32Bits << std::endl;
	std::cout << "LSB32: " << std::hex << low32Bits << std::endl;
	std::cout << "1: " << std::hex << high1_16 << std::endl;
	std::cout << "2: " << std::hex << high2_16 << std::endl;
	std::cout << "3: " << std::hex << low1_16  << std::endl;
	std::cout << "4: " << std::hex << low2_16  << std::endl;
	std::cout << "Value: " << std::dec << testValue << std::endl;

	return 0;
}
