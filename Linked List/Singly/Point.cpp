
#include <iostream>
#include <iomanip>
using namespace std;

struct Diem
{
	float x;
	float y;
};

struct Node
{
	Diem info;
	Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

void Nhap(Diem&);
void Xuat(Diem);
Node* GetNode(Diem);
void Init(List&);
void AddTail(List&, Node*);
void Input(List&,float&);
float TinhKC(Diem);
bool KiemTra(Diem,float);
void Output(List,float);

int main()
{
	List l;
	Init(l);
	float k;
	Input(l,k);
	Output(l,k);
	system("pause");
	return 0;
}

void Nhap(Diem &D)
{
	cout << "Nhap toa do x = ";
	cin >> D.x;
	cout << "Nhap toa do y = ";
	cin >> D.y;
}

void Xuat(Diem D)
{
	cout << "(" << fixed << setprecision(2) <<D.x << "," << fixed << setprecision(2)<< D.y << ")";
}

Node* GetNode(Diem D)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->info = D;
	p->pNext = NULL;
	return p;
}

void Init(List&l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void AddTail(List&l, Node*p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void Input(List&l,float &k)
{
	int n;
	cout << "Nhap so diem: ";
	cin >> n;
	Init(l);
	cout << "Nhap danh sach cac diem: " << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << endl;
		Diem D;
		Nhap(D);
		Node*p = GetNode(D);
		AddTail(l, p);
	}

	cout << "Nhap khoang cach k: ";
	cin >> k;
}

float TinhKC(Diem D)
{
	return sqrt(D.x*D.x + D.y*D.y);
}

bool KiemTra(Diem D, float k)
{
	if (TinhKC(D) == k)
		return true;
	else
		return false;
}

void Output(List l,float k)
{
	if (l.pHead == NULL)
		return;
	Node*p = l.pHead;
	int i = 1;
	bool flag = false;
	do {
		if (KiemTra(p->info, k) == true)
		{
		cout << "Diem " << i << ": ";
		Xuat(p->info);
		cout << ";" << fixed << setprecision(2) << TinhKC(p->info) <<endl;
		flag = true;
		}
		p = p->pNext;
		i++;
	} while (p != NULL);
	if (flag == false)
		cout << "KHONG CO KHOANG CACH LON THU "<<k;
}


