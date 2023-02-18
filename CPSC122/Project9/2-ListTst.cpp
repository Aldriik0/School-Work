#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
/*
 //Static list 
 List lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << endl;
 lst.DeleteItemH();
 cout << endl;
 lst.Print();
 cout << endl;


 //Dynamic list 
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;
 lst1->DeleteItemH();
 cout << endl;
 lst1->Print();

 delete lst1; //necessary to invoke destructor on dynamic list
 cout << endl;
 */
 
 /*
 List lst;
 for(int k=0; k<5; k++)
   lst.PutItemH(k);
 lst.Print();
 int location = lst.Find(1) + 1;
 cout << "Here is the location of 1: " << location << endl;
 */
 
 /*
 List lst;
 for(int k=0; k<5; k++)
	 lst.PutItemH(k);
 lst.Print();
 int delAmount = lst.DeleteItem(2);
 cout << "The amount of items that were deleted: " 
	  << delAmount << endl;
 lst.Print();
 */
 
 /*
 List lst;
 for(int k=0; k<5; k++)
	 lst.PutItemH(k);
 lst.Print();
 int size = lst.GetLength();
 cout << "Here is the length of the linked list: " << size << endl;
 */
 
 /*
 List lst;
 bool isEmpty = lst.IsEmpty();
 if(isEmpty == true)
	 cout << "There is no list" << endl;
 for(int k=0; k<5; k++)
	 lst.PutItemH(k);
 isEmpty = lst.IsEmpty();
 if(isEmpty == false)
	 cout << "There is a list, here it is: " << endl;
 lst.Print();
 */
 
 return 0;
}
