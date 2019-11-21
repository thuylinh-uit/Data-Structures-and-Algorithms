/* Viet chuong trinh thuc hien cac yeu cau sau:
	- Khai bao cau truc du lieu cua mot danh sach lien ket don vong de luu toa do cac dinh cua mot da giac loi trong mat phang Oxy
	- Tinh chu vi cua da giac
	- Dien tich cua da giac
*/
#include <iostream>
using namespace std;

struct diem
{
	int x;
	int y;
};
typedef diem DIEM;

struct node
{
	DIEM info;
	node *pNext;
	node *pPrev;
};
typedef node NODE;

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef list LIST;

void Init(LIST&);
void Input(LIST&);
void Input_Diem(DIEM&);
NODE *GetNode(DIEM);
void AddHead(LIST&, NODE*);
double Distance(DIEM, DIEM);
double Perimeter(LIST);
double Area(LIST);

int main()
{
	LIST l;
	Input(l);
	cout << "Chu vi: " << Perimeter(l) << endl;
	cout << "Dien tich: " << Area(l) << endl;
	system("pause");
	return 0;
}

void Init(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void Input(LIST &l)
{
	cout << "(n-giac) n=  ";
	int n;
	cin >> n;
	Init(l);
	cout << "Nhap cac dinh: " << endl;
	for (int i = 0; i < n; ++i)
	{
		DIEM x;
		Input_Diem(x);
		NODE *p = GetNode(x);
		AddHead(l, p);
	}
}

void Input_Diem(DIEM &x)
{
	cin >> x.x;
	cin >> x.y;
}

NODE *GetNode(DIEM x)
{
	NODE *p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddHead(LIST &l, NODE *p)
{
	if (p == NULL)
		return;
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pTail->pNext = p;
		l.pHead = p;
	}
}

double Distance(DIEM a, DIEM b)
{
	return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}

double Perimeter(LIST l)
{
	double p = 0;
	NODE *temp = l.pHead;
	do
	{
		p += Distance(temp->info, temp->pNext->info);
		temp = temp->pNext;
	} while (temp != l.pHead);
	return p;
}

double TriangleArea(double a, double b, double c)
{
	double temp = (a + b + c) / 2;
	return sqrt((temp - a)*(temp - b)*(temp - c)*temp);
}

double Area(LIST l)
{
	double s = 0;
	if (l.pHead != NULL)
	{
		NODE *p = l.pHead->pNext;
		NODE *q = p->pNext;
		do
		{
			s += TriangleArea(Distance(l.pHead->info, p->info), Distance(p->info, q->info), Distance(l.pHead->info, q->info));
			p = p->pNext;
			q = q->pNext;
		} while (q != l.pHead);
	}
	return s;
}
