//Viet ham xuat danh sach lien ket don vong cac so phuc
#include <iostream>
using namespace std;

struct sophuc
{
	int re, i;
};
typedef sophuc SOPHUC;

struct node
{
	SOPHUC info;
	node*pNext;
};
typedef node NODE;

struct list
{
	NODE*pHead;
	NODE*pTail;
};
typedef list LIST;

void Init(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* Get_Node(SOPHUC A) // tao node cho dslk
{
	NODE *p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = A;
	p->pNext = p;
	return p;
}
void Add_Tail(LIST &l, NODE*p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		p->pNext = l.pHead;
		l.pTail = p;
	}
}
void Nhap(LIST &l)
{
	SOPHUC A;
	cout << "Nhap phan thuc: ";
	cin >> A.re;
	cout << "Nhap phan ao: ";
	cin >> A.i;
	NODE*p = Get_Node(A);
	Add_Tail(l, p);
}

void Input(list &l)
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	Init(l);
	cout << "Nhap DSLK: ";
	for (int i = 1; i <= n; i++)
	{
		Nhap(l);
	}
}
void Xuat(SOPHUC A)
{
	cout << A.re << "+" << A.i << "i" << endl;
}
void output(LIST l)
{
	if (l.pHead == NULL)
		return;
	NODE *p = l.pHead;
	do
	{
		Xuat(p->info);
		p = p->pNext;
	} while (p != l.pHead);
}
int main()
{
	LIST l;
	Input(l);
	output(l);
	system("pause");
	return 0;
}

