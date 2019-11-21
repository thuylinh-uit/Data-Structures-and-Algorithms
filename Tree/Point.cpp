#include <iostream>
using namespace std;

struct diem
{
	float x, y;
	float khoangcach()
	{
		return sqrt(x*x + y*y);
	}
};

struct node
{
	diem info;
	node*pLeft;
	node*pRight;
};

typedef node* tree;

void Init(tree &t)
{
	t = NULL;
}
int IsEmpty(tree t)
{
	if (t == NULL)
		return 1;
	return 0;
}
void Insert_Node(tree &t, diem x)
{
	if (t == NULL) {
		node*p = new node;
		p->info = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (t->info.khoangcach() < x.khoangcach())
			Insert_Node(t->pRight, x);
		else if (t->info.khoangcach() > x.khoangcach())
			Insert_Node(t->pLeft, x);
	}
}

void Nhap(diem &d)
{
	cin >> d.x >> d.y;
}

void Input(tree &t)
{
	int n;
	cin >> n;
	Init(t);
	for (int i = 1; i <= n; i++)
	{
		diem d;
		Nhap(d);
		Insert_Node(t, d);
	}
}

void xuatDiem(diem d)
{
	cout << fixed << setprecision(2) << d.x << " " << fixed << setprecision(2) << d.y;
}

void LNR(tree t)
{
	if (t != NULL)
	{
		LNR(t->pLeft);
		xuatDiem(t->info);
		LNR(t->pRight);
	}
}

void NLR(tree t)
{
	if (t != NULL)
	{
		xuatDiem(t->info);
		LNR(t->pLeft);
		LNR(t->pRight);
	}
}

int main()
{
	tree t;
	Input(t);
	cout << "Duyet NLR:"<<endl;
	NLR(t);
	cout << "Duyet LNR:"<<endl;
	LNR(t);
	return 0;
}
