#include <iostream>
using namespace std;

#include "3-List.h"

ListT::ListT()
{
 length = 0;
 head = NULL;
 tail = NULL;
}

ListT::~ListT()
{
 while(length > 0)
  DeleteItemH();
}

void ListT::PutItemH(itemType item)
{
	node* tmp;
	bool isEmpty = IsEmpty();
	if(isEmpty == true)
	{
		head = new node;
		head->item = item;
		tail = head;
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

void ListT::Print() const
{
 node* cur = head;
 while(cur != NULL)
 {
  cout << cur->item << endl;
  cur = cur->next;
 }
}

itemType ListT::GetItemH() const
{
	return head->item;
}

void ListT::DeleteItemH()
{
	node* nodePtr;
	nodePtr = head->next;
	delete head;
	head = nodePtr;
	nodePtr = NULL;
	length--;
}

bool ListT::IsEmpty() const
{
	if(length == 0)
		return true;
	else
		return false;
}

int ListT::GetLength() const
{
	return length;
}

int ListT::FindItem(const itemType target) const
{
	int amount = 1;
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

int ListT::DeleteItem(const itemType target)
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
		if(tail->item == target)
		{
			DeleteItemT();
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
	tail = head;
	while(tail->next)
		tail = tail->next;
	return delAmount;
}	

//Now the fun begins with the tail pointer

void ListT::PutItemT(const itemType itemIn)
{
	node* tmp = new node;
	tmp->item = itemIn;
	tail->next = tmp;
	tail = tmp;
	tmp = NULL;	
}

itemType ListT::GetItemT() const
{
	return tail->item;
}

void ListT::DeleteItemT()
{
	node* tmp = PtrTo();
	delete tmp->next;
	tail = NULL;
	tmp->next = tail;
	tmp = NULL;
	length--;
}

node* ListT::PtrTo() 
{
	node* curr = head;
	while(curr->next != tail)
		curr = curr->next;
	return curr;
}

