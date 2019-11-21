#include <iostream>
#include <string>
using namespace std;

struct node
{
	string maso;
	string name;
	int soluong;
	node*pNext;
};
struct list
{
	node*pHead;
	node*pTail;
};
void Init(list &l) 
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node* Get_Node(string x,string y,int z) 
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->maso = x;
	p->name = y;
	p->soluong = z;
	p->pNext = NULL;
	return p;
}
void Add_Tail(list &l,node*p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Input(list &l)
{
	{
		int n;
		cout << "Nhap n: ";
		cin >> n;
		Init(l);
		cout << "Nhap Danh Sach Hang Hoa: " <<  endl ;
		for (int i = 1; i <= n; i++)
		{
			cout << i << endl;

			cin.ignore();
			string x;			
			cout <<"Nhap maso: "; getline(cin, x);
			

			string y; 
			cout << "Nhap ten: "; getline(cin, y);
			

			int z; 
			cout << "Nhap soluong: "; cin >> z;

			node*p = Get_Node(x, y, z);
			if (p)
				Add_Tail(l, p);
		}
	}
}

void Output(list l)
{
	if (l.pHead == NULL)
		return;
	node*p = l.pHead;
	cout << " DS hang hoa bao gom: " << endl ;
	int i = 1;
	do {
		cout << i << ".";
		
		cout << "Ma so: " << p->maso << endl;
	
		cout << "Ten: " << p->name << endl;
		
		cout << "So luong: " << p->soluong << endl;
		p = p->pNext;
		i++;
		cout << endl;
	} while (p != NULL);
}

void Sapxep(list &l)
{
	for (node*p = l.pHead; p != l.pTail; p = p->pNext)
	{
		for (node*q = p->pNext; q; q = q->pNext)
		{
			if (p->soluong > q->soluong) 
			{
				swap(p->maso, q->maso);
				swap(p->name, q->name);
				swap(p->soluong, q->soluong);
			}
		}
	}
}

int main()
{
	list l;
	Input(l);
	Sapxep(l);
	cout << "--------------" <<endl;
	Output(l);
	system("pause");
	return 0;
}