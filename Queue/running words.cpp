
//Dung Queue mo phong dong chu chay quanh man hinh. 

#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;

struct node
{
	char token;
	node * pNext;
};

struct Queue
{
	node * bottom;
	node * top;
};

void Init(Queue & que)
{
	que.bottom = NULL;
	que.top = NULL;
}

node * GetNode(char t)
{
	node * p = new node;
	if (p == NULL)
		return NULL;
	p->pNext = NULL;
	p->token = t;
	return p;
}

void EnQueue(Queue & que, char t)
{
	node * p = GetNode(t);
	if (que.top == NULL)
		que.bottom = que.top = p;
	else
	{
		que.bottom->pNext = p;
		que.bottom = p;
	}
}

node * DeQueue(Queue & que)
{
	if (que.top == NULL)
		return NULL;
	node * p = que.top;
	que.top = que.top->pNext;
	p->pNext = NULL;
	return p;
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void handle(Queue & que1, string str)
{

	string running;
	for (int i = 0; i < str.length(); i++)
	{
		EnQueue(que1, str[i]);
	}
	if (str[str.length() - 1] != ' ')
		EnQueue(que1, ' ');
	gotoxy(60 - 18, 0);
	cout << "Chu chay man hinh: ";
	while (!_kbhit())
	{
		gotoxy(60 - 20, 1);
		running += que1.top->token;
		cout << running;
		if (running.length() >= 20)
			running.erase(0, 1);
		EnQueue(que1, DeQueue(que1)->token);
		Sleep(100);
	}
}

int main()
{
	Queue _q1;
	Init(_q1);
	string str = "Thay Tien is the Best!!!";
	handle(_q1, str);

	return 0;
}