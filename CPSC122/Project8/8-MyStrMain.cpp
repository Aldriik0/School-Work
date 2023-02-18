/*
Name: Connor Jones
Class: CPSC 122, Section 1
Date Due: April 4, 2022
Assignment: Project 7
Description: Program illustrates using class MyString 
*/

#include "8-MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
/*
//Dr. De Palma's example:
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);

 //Test of myDisplay
 cout << "***************************************" << endl;
 cout << "*****Test 1 myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2  myDisplay*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myDisplay

 delete str2;
 */
 
 /*
 //Me testing if myStrcpy function works, and how I can utilize it
 MyString str1(argv[1]);
 cout << "Here it should print the first argument: " << endl;
 str1.myDisplay();
 cout << endl;
 str1.myStrcpy(argv[2]);
 cout << "Here it should print the second argument: " << endl;
 str1.myDisplay();
 cout << endl;
 */
 
 /*
 //Me testing if myStrlen works, and how I can utilize it
 MyString str1(argv[1]);
 int test = str1.myStrlen();
 cout << "Here is the number of characters in your first argument: "
	  << test << endl;
 */
 
 /*
 //Me testing if isEqual works, and how I can utilize it
 MyString str1(argv[1]);
 bool isEqual = str1.isEqual(argv[2]);
 if(isEqual == true)
	cout << "Arguments 1 and 2 are the same!" << endl;
 else
	cout << "Arguments 1 and 2 are NOT the same!" << endl;
 */
 
 /*
 //Me testing if find works, which uses isSub inside of it
 MyString str1(argv[1]);
 int subStartPos = str1.find(argv[2]) + 1;
 cout << "Here is the position of the substring's beginning!"
	  << "Position: " << subStartPos << endl;
 
 */
 
 /*
 //Here is the test for concat()
 MyString str1(argv[1]);
 cout << "Here is the quote you entered: " << endl;
 str1.myDisplay();
 cout << "Here is the quote you entered concatenated: " << endl;
 str1.concat(argv[1]);
 str1.myDisplay();
 */
 
 return 0;  
}