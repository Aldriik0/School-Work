#include <iostream>
using namespace std;

#include "3-List.h"

int main()
{
 //Static list 
 ListT lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << endl;
 lst.DeleteItemT();
 lst.Print();
 return 0;
}