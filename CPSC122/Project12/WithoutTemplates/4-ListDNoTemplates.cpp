#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

ListD::ListD()
{
 InitializeVars();
}

ListD::ListD(ListD* lst)
{
 InitializeVars();
 //returns a pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}

void ListD::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

//how would you do this?
ListD::~ListD()
{
	while(length > 0)
		Delete(length);
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

void ListD::PrintBackward()
{
	doubleNode* cur = tail->prev;
	int k = length;
	while(k > 0)
	{
		cout << cur->item << endl;
		cur = cur->prev;
		k--;
	}
}

void ListD::Delete(int pos)
{	
	if(pos == 1)
	{
		doubleNode* nodePtr;
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		nodePtr = NULL;
	}
	if(pos == length)
	{
		doubleNode* tmp = PtrTo();
		delete tmp->next;
		tail = NULL;
		tmp->next = tail;
		tmp = NULL;
	}
	else
	{
		doubleNode* curr = head;
		doubleNode* backNode = head;
		doubleNode* frontNode = head;
		for(int k=0; k<pos; k++)
			curr = curr->next;
		for(int k=0; k< pos-1; k++)
			backNode = backNode->next;
		for(int k=0; k< pos+1; k++)
			frontNode = frontNode->next;
		backNode->next = frontNode;
		frontNode->prev = backNode;
		curr->next = NULL;
		curr->prev = NULL;
		delete curr;
		curr = NULL, backNode = NULL, frontNode = NULL;
	}
	length--;
}

int ListD::DeleteAll(itemType item)
{
	int delAmount = 0, location = 1;
	doubleNode* curr = head;
	
	while(curr->next)
	{
		if(head->item == item)
		{
			Delete(1);
			length--;
			delAmount++;
		}
		if(tail->item == item)
		{
			Delete(length);
			length--;
			delAmount++;
		}
		if(curr->item == item)
		{
			Delete(location);
			length--;
			delAmount++;
		}
		else
		{
			curr = curr->next;
			location++;
		}
	}
	return delAmount;
}

void ListD::Sort()
{
 doubleNode* idxSmall;
 doubleNode* start = head;
 int pass = 0;
 while(pass < length - 1)
 {
	 idxSmall = FindSmall(start);
	 Swap(start, idxSmall);
	 start = start->next;
	 pass++;
	 //cout << "Working" << endl;
 }
 doubleNode* chckEnd = PtrTo();
 if(chckEnd->item > tail->item)
	 Swap(chckEnd, tail);
 chckEnd = NULL;
 idxSmall =	NULL;
 start = NULL;
}

void ListD::Swap(doubleNode* first, doubleNode* second)
{
	doubleNode* tmp = new doubleNode;
	
	tmp->item = first->item;
	first->item = second->item;
	second->item = tmp->item;
	
	delete tmp;
}

doubleNode* ListD::FindSmall(doubleNode* start)
{
 doubleNode* tmp;
 doubleNode* idxSmall;
 idxSmall = start;
 tmp = start;
 tmp = tmp->next;
 while(tmp->next != NULL)
 {
	 if(tmp->item < idxSmall->item)
		 idxSmall = tmp;
	 tmp = tmp->next;
 }
 
 return idxSmall;
}

doubleNode* ListD::PtrTo() 
{
	doubleNode* curr = head;
	while(curr->next != tail)
		curr = curr->next;
	return curr;
}

