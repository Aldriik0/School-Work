#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"


template <typename T>
ListD<T>::ListD()
{
 InitializeVars();
}

template <typename T>
ListD<T>::ListD(ListD* lst)
{
 InitializeVars();
 //returns a pointer to the first node, which is what we want here
 doubleNode<T>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}

template <typename T>
void ListD<T>::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

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
template <typename T>
ListD<T>::~ListD()
{
	while(length > 0)
		Delete(length);
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode<T>* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 

template <typename T>
void ListD<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode<T>* insertPtA = FindPosition(pos);  
 doubleNode<T>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<T>* tmp = new doubleNode<T>; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template <typename T>
void ListD<T>::PrintForward()
{
 doubleNode<T>*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

template <typename T>
void ListD<T>::PrintBackward()
{
	doubleNode<T>* cur = tail->prev;
	int k = length;
	while(k > 0)
	{
		cout << cur->item << endl;
		cur = cur->prev;
		k--;
	}
}

template <typename T>
void ListD<T>::Delete(int pos)
{	
	if(pos == 1)
	{
		doubleNode<T>* nodePtr;
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		nodePtr = NULL;
	}
	if(pos == length)
	{
		doubleNode<T>* tmp = PtrTo();
		delete tmp->next;
		tail = NULL;
		tmp->next = tail;
		tmp = NULL;
	}
	else
	{
		doubleNode<T>* curr = head;
		doubleNode<T>* backNode = head;
		doubleNode<T>* frontNode = head;
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

template <typename T>
int ListD<T>::DeleteAll(T item)
{
	int delAmount = 0, location = 1;
	doubleNode<T>* curr = head;
	
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

template <typename T>
void ListD<T>::Sort()
{
 doubleNode<T>* idxSmall;
 doubleNode<T>* start = head;
 int pass = 0;
 while(pass < length - 1)
 {
	 idxSmall = FindSmall(start);
	 Swap(start, idxSmall);
	 start = start->next;
	 pass++;
	 //cout << "Working" << endl;
 }
 doubleNode<T>* chckEnd = PtrTo();
 if(chckEnd->item > tail->item)
	 Swap(chckEnd, tail);
 chckEnd = NULL;
 idxSmall =	NULL;
 start = NULL;
}

template <typename T>
void ListD<T>::Swap(doubleNode<T>* first, doubleNode<T>* second)
{
	doubleNode<T>* tmp = new doubleNode<T>;
	
	tmp->item = first->item;
	first->item = second->item;
	second->item = tmp->item;
	
	delete tmp;
}

template <typename T>
doubleNode<T>* ListD<T>::FindSmall(doubleNode<T>* start)
{
 doubleNode<T>* tmp;
 doubleNode<T>* idxSmall;
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

template <typename T>
doubleNode<T>* ListD<T>::PtrTo() 
{
	doubleNode<T>* curr = head;
	while(curr->next != tail)
		curr = curr->next;
	return curr;
}