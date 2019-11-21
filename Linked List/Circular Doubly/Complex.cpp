//Viet ham tao node trong danh sach lien ket kep vong cac so phuc + Tinh Tong

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
	node*pPrev;
};
typedef node NODE;

struct list
{
	NODE*pHead;
	NODE*pTail;
};
typedef list LIST;

void Init(LIST &l) {
	l.pHead = l.pTail = NULL;
}

NODE *GetNode(SOPHUC x)
{
	NODE *p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = p;
	p->pPrev = p;
	return p;
}

void AddTail(LIST &l, NODE *p)
{
	if (l.pHead == NULL)  //kiem tra xem dslk co rong khong
		l.pHead = l.pTail = p;
	else if (l.pHead == l.pTail)
	{ //kiem tra xem dslk co 1 phan tu hay khong
		l.pHead->pNext = p;
		l.pHead->pPrev = p;
		p->pPrev = l.pHead;
		p->pNext = l.pHead;
		l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pTail = p;
	}
}
void Nhap(LIST &l)
{
	SOPHUC A;
	cout << "Nhap phan thuc: "; cin >> A.re;
	cout << "Nhap phan ao: "; cin >> A.i;
	NODE*p = GetNode(A);
	AddTail(l, p);
}
void Input(LIST &l)
{
	int n;
	cout << "Nhap so luong phan tu: "; cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		Nhap(l);
	}
}
SOPHUC TinhTong(LIST l)
{
	SOPHUC S;
	S.i = 0;
	S.re = 0;
	NODE*p = l.pHead;
	do
	{
		S.i += p->info.i;
		S.re += p->info.re;
		p = p->pNext;
	} while (p != l.pHead);
	return S;
}
void Xuat(SOPHUC a)
{
	cout << a.re << "+" << a.i << "i" << endl;
}
int main()
{
	LIST l;
	Input(l);
	Xuat(TinhTong(l));
	system("pause");
	return 0;
}
