/*****************************************************************************\
*                        Logical Address Translator                           *
*																			  *
* Author: Blakely Fabiani 													  *
* Contact: BlakelyFabiani@gmail.com                                            *                        
* Date: June 12, 20018                                                        *
* Copyright (c) 2018 Blakely Fabiani		  								  *
*																		      *
* Permission is hereby granted, free of charge, to any person obtaining       *
* a copy of this software and associated documentation files (the             *
* "Software"), to deal in the Software without restriction, including         *
* without limitation the rights to use, copy, modify, merge, publish,         *
* distribute, sublicense, and/or sell copies of the Software, and to		  *
* permit persons to whom the Software is furnished to do so, subject to       *
* the following conditions:													  *
*																		      *
* The above copyright notice and this permission notice shall be included     *
* in all copies or substantial portions of the Software.					  *
\*****************************************************************************/

#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

int key, offsetShift, logicalAddr, offset, pageNum, frameNum, PhysicalAddr;

void initProgram();
void getParameters();
void getOffset();
void getPageNumber();
void calcPysicalAddr();

int main(int argc, char *argv[]) {
	
	initProgram();
	getParameters();
	getPageNumber();
	getOffset();
	calcPysicalAddr();
	
	
}

void initProgram(){
	
	cout << "----------Page Size Key----------\n"; // prints Output Key for Page Size
	cout << "---- bytes ----------- code -----\n"; //
	cout << "----  512  -----------  1   -----\n"; //
	cout << "----  1024 -----------  2   -----\n"; //
	cout << "----  2048 -----------  3   -----\n"; //
	cout << "----  4096 -----------  4   -----\n"; //
	cout << "----  8192 -----------  5   -----\n"; //
	cout << "---------------------------------\n\n\n"; //
}

//Reads in information about the problem from the user.
void getParameters(){
	int in;
	cout << "Enter the code for the desired page size: "; // prompt user for key
	cin >> in;
	key = in;
	cout << "\n";
	
	if(in == 1) {
		cout << "You entered a page size of: ";
		cout << "512 bytes";
		offsetShift = 9;
	}
	else if(in == 2) {
		cout << "You entered a page size of: ";
		cout << "1024 bytes";
		offsetShift = 10;
	}
	else if(in == 3) {
		cout << "You entered a page size of: ";
		cout << "2048 bytes";
		offsetShift = 11;
	}
	else if(in == 4) {
		cout << "You entered a page size of: ";
		cout << "4096 bytes";
		offsetShift = 12;
	}
	else if(in == 5) {
		cout << "You entered a page size of: ";
		cout << "8192 bytes";
		offsetShift = 13;
	}
	else {
		cout << "You entered an invalid number. \n";
		cout << "Please refer to the Key and try again.\n\n\n";
		getParameters();
	}
	
	cout << "\n\n\nEnter the Logical Address in Hexadecimal. (DO NOT INCLUDE 0x) : "; // prompt user for logical Address
	cin >> hex >> in;
	logicalAddr = in;
	cout << "\n";
	
	cout << "You entered a Logical Address of: 0x"; // print value in hex
	cout << std::hex << logicalAddr << '\n';
	
}


void getPageNumber(){
	
	int temp = logicalAddr;
	pageNum = (temp >> offsetShift);
	cout << "\nThe Page number in decimal is: "; // print page number value in Decimal
	cout << pageNum << '\n';
	cout << "The Page number in Hex is: 0x"; // print page number value in Hex
	cout << std::hex << pageNum << '\n';
	cout << "The Page number in Binary is: "; // print page number value in Binary
	//cout << std::bitset<32>(pageNum) << '\n';
	
	switch(int(log2(pageNum)+1)) {
		case 0: // 00
		cout << std::bitset<4>(pageNum) << '\n';
			break;
		case 1: // 0001
			cout << std::bitset<4>(pageNum) << '\n';
			break;
		case 2: // 0010
			cout << std::bitset<4>(pageNum) << '\n';
			break;
		case 3: // 0011
			cout << std::bitset<4>(pageNum) << '\n';
			break;
		case 4: // 0100
			cout << std::bitset<4>(pageNum) << '\n';
			break;
		case 5: // 0101
			cout << std::bitset<8>(pageNum) << '\n';
			break;
		case 6: // 0110
			cout << std::bitset<8>(pageNum) << '\n';
			break;
		case 7: // 0111
			cout << std::bitset<8>(pageNum) << '\n';
			break;
		case 8: // 1000
			cout << std::bitset<8>(pageNum) << '\n';
			break;
		case 9: // 1001
			cout << std::bitset<12>(pageNum) << '\n';
			break;
		case 10: // 1010
			cout << std::bitset<12>(pageNum) << '\n';
			break;
		case 11: // 1011
			cout << std::bitset<12>(pageNum) << '\n';
			break;
		case 12: // 1100
			cout << std::bitset<12>(pageNum) << '\n';
			break;
		case 13: // 1101
			cout << std::bitset<16>(pageNum) << '\n';
			break;
		case 14: // 1110
			cout << std::bitset<16>(pageNum) << '\n';
			break;
		case 15: // 1111
			cout << std::bitset<16>(pageNum) << '\n';
			break;
		case 16: // 0001 1111
			cout << std::bitset<16>(pageNum) << '\n';
			break;
		case 17: // 0010 1111
			cout << std::bitset<20>(pageNum) << '\n';
			break;
		case 18: // 0011 1111
			cout << std::bitset<20>(pageNum) << '\n';
			break;
		case 19: // 0100 1111
			cout << std::bitset<20>(pageNum) << '\n';
			break;
		case 20: // 0101 1111
			cout << std::bitset<20>(pageNum) << '\n';
			break;
		case 21: // 0110 1111
			cout << std::bitset<21>(pageNum) << '\n';
			break;
		case 22: // 0111 1111
			cout << std::bitset<22>(pageNum) << '\n';
			break;
		default:
			cout << std::bitset<32>(pageNum) << '\n';
			break;
		}
	
}

void getOffset(){
	int temp = pageNum;
	int temp2 = logicalAddr;
	temp = (temp << offsetShift);
	offset = (temp2 ^ temp);
	cout << "\n\nThe Offset in decimal is: "; // print offset value in decimal
	cout << std::dec << offset << '\n';
	cout << "The Offset in Hex is: 0x"; // print offset value in Hex
	cout << std::hex << offset << '\n';
	cout << "The Offset in Binary is: "; // print offset value in Binary
	//cout << std::bitset<32>(offset) << '\n';
	
	switch(offsetShift) {
		case 9: // 01
			cout << std::bitset<9>(offset) << '\n';
			break;
		case 10: // 10
			cout << std::bitset<10>(offset) << '\n';
			break;
		case 11: // 11
			cout << std::bitset<11>(offset) << '\n';
			break;
		case 12: // 10
			cout << std::bitset<12>(offset) << '\n';
			break;
		case 13: // 11
			cout << std::bitset<13>(offset) << '\n';
			break;
		default:
			cout << std::bitset<32>(offset) << '\n';
			break;
	}
}

void calcPysicalAddr(){
	int in, shift;
	cout << "\n\n\nEnter the Frame number in Hexadecimal. (DO NOT INCLUDE 0x) : "; // prompt user for frame number
	cin >> hex >> in;
	frameNum = in;
	cout << "\n";
	
	cout << "You entered a frame number of: 0x"; // print value in hex
	cout << std::hex << frameNum << '\n';
		
	
	shift = int(log2(offset)+1);	
	PhysicalAddr = (frameNum << offsetShift);
	PhysicalAddr = (PhysicalAddr ^ offset); 
	//Cheating and just printing them out for now because the above calculation isnt working.	
	//cout << "\n\nThe Physical Address in Hex is: 0x";
	//cout << std::hex << frameNum;
	//cout << std::hex << offset << '\n';
	cout << "\n\nThe Physical Address in Hex is: 0x";
	cout << std::hex << PhysicalAddr << '\n';
	cout << "The Physical Address in Binary is: ";
	cout << std::bitset<32>(PhysicalAddr) << '\n';
}