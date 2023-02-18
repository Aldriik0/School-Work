#include <iostream>
using namespace std;

#include "4-ListD.h"

//All tests are separated by function
void TestInsert();
void TestCopyConstructor();
void TestPrintForwards();
void TestPrintBackwards();
void TestDelete();
void TestSort();

int main()
{
 //TestInsert();
 //TestCopyConstructor();
 //TestPrintForwards();
 //TestPrintBackwards();
 //TestDelete();
 //TestSort();
}



void TestInsert()
{

 ListD<int>* lst = new ListD<int>;
 for (int i = 1; i <= 5; i++)
  lst->Insert(i,i);
 lst->PrintForward();

 //test general case insert
 cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines" << endl;
 lst->PrintForward();
 cout << endl;

 //test insert at the head
 lst->Insert(0,1);
 cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
 lst->PrintForward();
 cout << endl;

 //test insert at the tail 
 lst->Insert(100,7);
 cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
 lst->PrintForward();
 cout << endl;
 
 //test insert in middle 
 lst->Insert(50,5);
 cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
 lst->PrintForward();
 cout << endl;
 //delete lst;
}

void TestCopyConstructor()
{
 ListD<int>* lst1 = new ListD<int>;
 for (int i = 1; i <= 3; i++)
  lst1->Insert(i,i);

 ListD<int>* lst2(lst1);
 
 cout << "Traverse lst1" << endl;
 lst1->PrintForward();
 cout << endl;
 cout << "Traverse lst2" << endl;
 lst2->PrintForward();

 //delete lst1;
 //delete lst2;
}

void TestPrintForwards()
{
	ListD<int>* lst = new ListD<int>;
	for(int k = 0; k < 5; k++)
		lst->Insert(k,k);
	cout << "Print forwards: " << endl;
	lst->PrintForward();
	
	delete lst;
}

void TestPrintBackwards()
{
	ListD<int>* lst = new ListD<int>;
	for(int k = 0; k < 5; k++)
		lst->Insert(k,k);
	cout << "Printing the list backwards: " << endl;
	lst->PrintBackward();
	
	delete lst;
}

void TestDelete()
{
	ListD<int>* lst = new ListD<int>;
	for(int k = 0; k < 5; k++)
		lst->Insert(k,k);
	lst->PrintForward();
	cout << "Deleting the 3rd node: " << endl;
	lst->Delete(3);
	lst->PrintForward();
	cout << "Deleting position 1: " << endl;
	lst->Delete(1);
	lst->PrintForward();
	
	delete lst;
}

void TestSort()
{
	ListD<int>* lst = new ListD<int>;
	unsigned seed = time(0);
	srand(seed);
	for(int k=0; k<5; k++)
	{
		int randNum = 1 + rand() % 5;
		lst->Insert(randNum,k);
	}
	cout << "Here is the list: " << endl;
	lst->PrintForward();
	cout << "Here is the list sorted: " << endl;
	lst->Sort();
	lst->PrintForward();
	
	
	delete lst;
}
	