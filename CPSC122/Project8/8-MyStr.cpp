#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>

//Constructor
MyString::MyString(char const* strIn)
{
 length = strlen(strIn);  //strlen function
 str = new char[length + 1];
 strcpy(str, strIn); //strlen function

}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
 //cout << "OMG, I'm about to be deleted" << endl;
 delete []str; 
}

void MyString::myDisplay()
{
 cout << str << endl;
}

void MyString::myStrcpy(char const* strIn)
{
	int j=0;
	if(str[0] != '\0')
	{
		while(str[j] != '\0')
			j++;
		for(int k=0; k<= j; k++)
			str[k] = '\0';
	}
	for(int k=0; strIn[k] != '\0'; k++)
		str[k] = strIn[k];
}

int MyString::myStrlen()
{
	int k = 0;
	while(str[k] != '\0')
		k++;
	int stringLen = k;
	return stringLen;
}

bool MyString::isEqual(char const* strIn)
{
	bool isEqual = true;
	int k = 0;
	while(str[k] != '\0')
	{
		if(str[k] != strIn[k])
		{
			isEqual = false;
			break;
		}
		k++;
	}
	return isEqual;
}

int MyString::find(char const* strIn)
{
	int k = 0;
	int j = 0;
	int marker;
	while(str[k] != '\0')
	{
		if(strIn[j] == '\0')
			break;
		if(strIn[j] == str[k])
		{
			if(j == 0)
				marker = k;
			j++;
		}
		
		k++;	
	}
	bool subCheck = isSub(strIn, marker);
	if(marker == 0)
		marker = -1;
	else
	{
		if(subCheck == false)
			marker = -1;
	}
	return marker;
}

void MyString::concat(char const* strIn)
{
	int k, j;
	k=0;
	j=0;
	while(strIn[k] != '\0')
	{
		if(strIn[j] == ' ')
		{
			j++;
		}
		else
		{
			str[k] = strIn[j];
			j++;
			k++;
		}
	}
}

bool MyString::isSub(char const* strIn, int idx)
{
	bool isSub = true;
	int k = idx;
	while(str[k] != '\0')
	{
		if(strIn[k] == '\0')
			break;
		if(str[k] != strIn[k])
		{
			isSub = false;
			break;
		}
		k++;
	}
	return isSub;
}