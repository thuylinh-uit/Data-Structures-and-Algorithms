// BT_QUEUE.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int info;
	node*pNext;
};
typedef node NODE;

struct queue
{
	NODE*pHead;
	NODE*pTail;
};
typedef queue QUEUE;

void Init(QUEUE &que)
{
	que.pHead = que.pTail = NULL;
}

NODE* Get_Node(int x)//for Input
{
	NODE *p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void Enque(QUEUE &que, NODE* p)
{
	if (que.pHead == NULL)
		que.pHead = que.pTail = p;
	else {
		que.pTail->pNext = p;
		que.pTail = p;
	}
}
void Input(QUEUE &queue,unsigned int x)
{
	Init(queue);
	while (x) {
		NODE*p = Get_Node(x % 10);
		Enque(queue, p);
		x /= 10;
	}
}

void Output(QUEUE queue )
{
	if (queue.pHead == NULL)
		return;
	node*p = queue.pHead;
	cout << "12567 ->  ";
	do {
		cout << p->info;
		p = p->pNext;
	} while (p != NULL);
}

int main()
{
	cout << "Viet chuong trinh nhap vao so nguyen khong am 12567, hien thi len man hinh so dao nguoc \n";
	QUEUE queue ;
	Input(queue,12567);
	Output(queue);
	cout << endl;
	system("pause");
	return 0;
}
