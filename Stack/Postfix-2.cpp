
//  Dùng stack để tính biểu thức toán học được nhập dạng hậu tố như sau: 
// Biểu thức hậu tố là biểu thức có dạng như sau: 532*+ <=> 5+(3*2)=11 

#include<iostream>
#include<string>
#define tem template<class type>
using namespace std;

tem
struct node
{
	type token;
	node * pNext;
};
tem
struct stack
{
	node<type> * top;
};
tem
void Init(stack<type> &s)
{
	s.top = NULL;
}
tem
node<type> * GetNode(type t)
{
	node<type> * p = new node<type>;
	if (p == NULL)
		return NULL;
	p->token = t;
	p->pNext = NULL;
}
tem
void Push(stack<type> &s, type t)
{
	node<type> * p = GetNode(t);
	if (s.top == NULL)
		s.top = p;
	else
	{
		p->pNext = s.top;
		s.top = p;
	}
}
tem
node<type> * Pop(stack<type> &s)
{
	if (s.top == NULL)
		return NULL;
	node<type> * t = s.top;
	s.top = s.top->pNext;
	t->pNext = NULL;
	return t;
}
tem
type Peak(stack<type> s)
{
	return s.top->token;
}

int CheckPriority(char c)
{
	if (c == '(')
		return 0;
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/' || c == '%')
		return 2;
	if (c == '^')
		return 3;
}

string InfixtoPostfix(string s)
{
	int solu;
	stack<char> st;
	Init(st);
	string hauto = "";
	for (int i = 0; i < s.length(); i++)
	{
		char token = s[i];
		if (token != ' ')
		{
			if (token - '0' >= 0 && token - '0' <= 9 || isalpha(token)) 
				hauto += token;
			else 
			{
				if (token == '(')
					Push(st, token);
				else 
					 
				{
					if (token == ')') 
					{
						while (st.top->token != '(')
						{
							hauto += ' ';
							hauto += Pop(st)->token;
						}
						Pop(st);
					}
					else 
					{
						if (st.top == NULL) 
						{
							hauto += ' ';
							Push(st, token);
						}
						else
						{  
							if (CheckPriority(token) <= CheckPriority(Peak(st)))
					
							{
								hauto += ' ';
								hauto += Pop(st)->token;
								hauto += ' ';
								Push(st, token);
							}
							else 
							{
								hauto += ' ';
								Push(st, token);
							}
						}
					}
				}
			}
		}
	}
	while (st.top)
	{
		hauto += ' ';
		hauto += Pop(st)->token;
	}
	cout << hauto << endl;
	return hauto;
}
float Evaluate(string Postfix)
{
	stack<float> st;
	Init(st);
	for (int i = 0; i < Postfix.size(); i++)
	{
		if (Postfix[i] != ' ')
		{
			if (Postfix[i] - '0' >= 0 && Postfix[i] - '0' <= 9)
			{
				Push(st, float(Postfix[i] - '0'));
			}
			else if (st.top)
			{
				float op1 = Peak(st); Pop(st);
				float op2 = Peak(st); Pop(st);
				if (Postfix[i] == '+') Push(st, op2 + op1);
				if (Postfix[i] == '-') Push(st, op2 - op1);
				if (Postfix[i] == '*') Push(st, op2 * op1);
				if (Postfix[i] == '/') Push(st, op2 / op1);
				if (Postfix[i] == '^') Push(st, pow(op2, op1));
				if (Postfix[i] == '%') Push(st, float(int(op2) % int(op1)));
			}

		}
	}
	if (st.top != NULL)
	{
		float result = Peak(st);
		Pop(st);
		return result;
	}
}
void main()
{
	string s;
	cout << "Nhap bieu thuc: ";
	getline(cin, s);
	string temp = InfixtoPostfix(s);
	cout << "Ket Qua: " << Evaluate(temp) << endl;

	system("pause");
}