// Viet ham tinh tong cac so le trong danh sach lien ket don vong cac so nguyen


#include <iostream>
using namespace std;

struct node
{
	int info;
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

NODE* Get_Node(int A) // tao node cho dslk
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

void Input(list &l)
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	Init(l);
	cout << "Nhap DSLK: ";
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		NODE*p = Get_Node(x);
		Add_Tail(l, p);
	}
}


int TinhTong(LIST l)
{
	if (l.pHead == NULL)
		return 0;
	int s = 0;
	node *p = l.pHead;
	do {
		if (p->info % 2 == 1)
			s += p->info;
		p = p->pNext;
	} while (p != l.pHead);
	return s;
}
int main()
{
	LIST l;
	Input(l);
	cout <<"Tong cac so le trong dslk la: "<<TinhTong(l)<<endl;
	system("pause");
	return 0;
}

