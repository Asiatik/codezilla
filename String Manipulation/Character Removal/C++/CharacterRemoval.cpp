// CharacterRemoval.cpp
// Implementation of function used to remove all occurences of a character from a string in C++
// Created by Efren Aguilar for the codezilla project

//#include "stdafx.h"

void removeCharsFromStr(char* str, char toRemove, int strLen)
{
	int numRemoved = 0;
	for (int i = 0; i < strLen; i++)
	{
		if (str[i] == toRemove)
		{
			numRemoved++;
			//Shift string down by one character
			for (int start = i; start < strLen - numRemoved; start++)
				str[start] = str[start+1];
			str[strLen - numRemoved] = '\0';

			//String shifted so keep iterator in place
			i--;
		}
	}
}

int main()
{
	char testStr[13] = "Hello World!";
	printf("String before removal %s", testStr);
	removeCharsFromStr(testStr, 'l', 13);
	printf("String after removal %s", testStr);
    return 0;
}

