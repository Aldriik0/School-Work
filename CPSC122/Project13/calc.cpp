#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
 stk = new Stack[26];
 inFix = argvIn;
 postFix = new char[strlen(inFix)];
 if(CheckTokens() == false)
 {
	 cout << "Invalid arithmetic expression inputted" << endl;
	 exit(EXIT_FAILURE);
 }
 MakeValueTbl();
 Parse();
 if(CheckParens() == false)
 {
	 cout << "Parends are not balanced" << endl;
	 exit(EXIT_FAILURE);
 }
 InFixToPostFix();
}

Calc::~Calc()
{}

bool Calc::CheckTokens()
{
 int x = 0;
 char ch;
 while(inFix[x] != '\0')
 {
	 ch = inFix[x];
	 //cout << ch << endl;
	 if(ch == ')')
		 x++;
	 else if(ch == '(')
		 x++;
	 else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		 x++;
	 else if(ch > 'A' && ch < 'Z')
		 x++;
	 else if(ch > 47 && ch < 58)
		 x++;
	 else if(ch == '\0')
		 break;
	 else
		 return false;
 }
 return true;
}

void Calc::MakeValueTbl()
{
	valueTbl = new int[26];
	valueIdx = 0;
	for(int k=0; k<26; k++)
		valueTbl[k] = 0;
}

void Calc::Parse()
{
	char* str = new char[strlen(inFix) + 1];
	char* str1 = new char[strlen(inFix) + 1];
	strcpy(str, inFix);
	strcpy(str1, inFix);
	char* tmp = new char[strlen(inFix) + 1];
	int i=0, k=0, alphC = 0;
	char alph = 'A';
	while(str[i] != '\0')
	{
		char ch = str[i];
		if(((ch >= '0') && (ch <= '9')))
		{
			tmp[k] = alph + alphC;
			alphC++;
			k++;
			i++;
			ch = str[i];
			while(((ch >= '0') && (ch <= '9')))
			{
				i++;
				ch = str[i];
			}
		}
		else
		{
			tmp[k] = ch;
			k++;
			i++;
		}
	}
	char delimiters[] = " ()+-*/";
	str = strtok(str1, delimiters);
	while(str != NULL)
	{
		valueTbl[valueIdx] = atoi(str);
		str = strtok(NULL, delimiters);
		valueIdx++;
	}
	strcpy(inFix, tmp);
}

bool Calc::CheckParens()
{
 bool isBalanced = true;
 int i = 0;
 while(inFix[i] != '\0')
 {
	 char ch = inFix[i];
	 if(ch == '(')
		 stk->Push('(');
	 else
	 {
		 if(ch == ')')
		 {
			 if(stk->IsEmpty() == false)
				 stk->Pop();
			 else
				 isBalanced = false;
		 }
	 }
	 i++;
 }
 if(isBalanced && stk->IsEmpty())
 {
	 isBalanced == true;
	 return isBalanced;
 }
 isBalanced = false;
 return isBalanced;
}

void Calc::DisplayInFix()
{
	char ch;
	int x = 0;
	while(inFix[x] != '\0')
	{
		ch = inFix[x];
		cout << ch;
		x++;
	}
	cout << endl;
}

void Calc::InFixToPostFix()
{
	int i = 0;
	int k = 0;
	while(inFix[i] != '\0')
	{
		char ch = inFix[i];
		if(ch == '(')
			stk->Push('(');
		else if((ch == '*') || (ch == '+') || (ch == '-') || (ch == '/'))
			stk->Push(ch);
		else if(ch == ')')
		{
			while(stk->Peek() != '(')
			{
				postFix[k] = stk->Peek();
				stk->Pop();
				k++;
			}
			stk->Pop();
		}
		else
		{
			postFix[k] = ch;
			k++;
		}
		i++;
	}
}

void Calc::DisplayPostFix()
{
	cout << postFix << endl;
}

int Calc::Evaluate()
{
 int result = 0;
 int i = 0;
 while(postFix[i] != '\0')
 {
	 char ch = postFix[i];
	 if((ch == '*') || (ch == '+') || (ch == '-') || (ch == '/'))
	 {
		 int op1;
		 int op2;
		 if(stk->Peek() != result)
			 op2 = valueTbl[(stk->Peek() - 'A')];
		 else
			 op2 = result;
		 stk->Pop();
		 if(stk->Peek() != result)
			 op1 = valueTbl[(stk->Peek() - 'A')];
		  else
			 op1 = result;
		 if(ch == '+')
			 result = op1 + op2;
		 else if(ch == '-')
			 result = op1 - op2;
		 else if(ch == '*')
			 result = op1 * op2;
		 else
			 result = op1 / op2;
		
		 stk->Pop();
		 stk->Push(result);
	 }
	 else
		 stk->Push(ch);
	 i++;
 }
 cout << stk->Peek() << endl;
 return stk->Peek();
}

int Calc::FindLast(int cur)
{
 int pos = cur;
 while(inFix[pos] > 47 && inFix[pos] < 58)
 {
	 pos++;
 }
 return pos;
}

