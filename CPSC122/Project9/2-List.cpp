#include <iostream>
using namespace std;

#include "2-List.h"


//Class-related functions
//Constructor
List::List()
{       
 length = 0;
 head = NULL;
}

//Destructor
List::~List()
{
 while(length > 0)
  DeleteItemH();
}

//Head-related functions
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
	length+=1;
}

itemType List::GetItemH() const
{
	return head->item;
}

void List::DeleteItemH()
{
	node* nodePtr;
	nodePtr = head->next;
	delete head;
	head = nodePtr;
	nodePtr = NULL;
	length--;
}


//General operations on the class

void List::Print() const
{
	node* traverser;
	traverser = head;
	while(traverser->next != nullptr)
	{
		cout << traverser->item << endl;
		traverser = traverser->next;
	}
	traverser = NULL;
}

bool List::IsEmpty() const
{
 bool emptyCheck = false;
 if(!head)
	 emptyCheck = true;
 return emptyCheck;
}



//Here's where I'm starting, until I can know why DePalma's example won't work
int List::GetLength() const
{
 return length;
}

int List::Find(const itemType target) const
{
	int amount = 0;
	node* traverser;
	traverser = head;
	while(traverser->next)
	{
		if(target == traverser->item)
			break;;
		traverser = traverser->next;
		amount+=1;
	}
	traverser = NULL;
	return amount;
}

int List::DeleteItem(const itemType target)
{
	node* prevNode;
	node* nodePtr;
	int delAmount = 0;
	
	nodePtr = head->next;
	prevNode = nodePtr;
	while(nodePtr->next)
	{
		if(head->item == target)
		{
			DeleteItemH();
			delAmount+=1;
		}
		if(nodePtr->item == target)
		{
			prevNode->next = nodePtr->next;
			delete nodePtr;
			nodePtr = prevNode;
			delAmount+=1;
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		else
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
	}
	prevNode = NULL;
	nodePtr = NULL;
	length = length - delAmount;
	return delAmount;
}	

