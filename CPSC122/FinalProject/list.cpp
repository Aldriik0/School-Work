#include <iostream>
using namespace std;

#include "list.h"


List::List()
{
	//Intializing all member variables
	head = NULL;
}

List::~List()
{
	node* tmp; //Need a node for the Destructor() input argument
	tmp = head; //set into head so that Destructor can reset it to head everytime
	Destructor(head);
	tmp = NULL; //Freeing up the space
}

int List::GetLength()
{
	node* tmp;
	tmp = head;
	static int statTrouble = 0; //used for correcting the GetLength() static int inside of it
	int length = GetLength(tmp) - statTrouble;
	
	//Incremementing so everytime GetLength is called it returns the actual length
	statTrouble += length; 
	return length;
}

int List::GetLength(node* cur)
{
	static int length = 0;
	if(cur == NULL)
		return length;
	length++;
	return GetLength(cur->next);
}

bool List::IsEmpty() //For use in PutItemH()
{
	int length = GetLength();
	if(length == 0)
		return true;
	return false;
}

void List::PutItemH(itemType item)
{
	node* tmp;
	bool isEmpty = IsEmpty();
	if(isEmpty == true)
	{
		head = new node;
		head->item = item;
	}
	else
	{
		tmp = head;
		head = new node;
		head->next = tmp;
		head->item = item;
		tmp = NULL;
	}
}

itemType List::GetItemH()
{
	return head->item;
}

void List::Print()
{
	node* tmp;
	tmp = head;
	Print(tmp);
	tmp = NULL;
}

void List::Print(node* cur)
{
	if(cur != NULL)
	{
		cout << cur->item << " ";
		return Print(cur->next);
	}
}

void List::PrintRev()
{
	node* tmp;
	tmp = head;
	PrintRev(tmp);
	tmp = NULL;
}

//I essentially have to reverse what I did in Print()
void List::PrintRev(node* cur)
{
	if(cur == NULL) //the break out case. As the recursion crosses the list, eventually cur 
		return;     //will hit the end, ie. NULL
	
	PrintRev(cur->next); // Goes till end of list, then using the breakout if statement
						//   it will print everything as it comes out of the recursion
	cout << cur->item << " "; // to print everything as it comes out of the recursion
}

void List::Destructor(node* cur)
{
	cur = head; //resets cur to head
	if(cur == NULL) //Once list is fully deleted breaks out of the recursion
		return;
	else
	{
		DeleteItemH();
		return Destructor(cur);
	}
}

void List::DeleteItemH()
{
	node* nodePtr;
	nodePtr = head->next;
	delete head;
	head = nodePtr;
	nodePtr = NULL;
}