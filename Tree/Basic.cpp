#include <iostream>
using namespace std;

struct node
{
	int info;
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
void Insert_Node(tree &t, int x)
{
	if (t == NULL) {
		node*p = new node;
		p->info = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (t->info < x)
			Insert_Node(t->pRight, x);
		else if (t->info > x)
			Insert_Node(t->pLeft, x);
	}

}
void Input(tree &t)
{
	int n;
	cout << "Nhap so node cua cay: "; cin >> n;
	Init(t);
	cout << "Nhap cac nut: ";
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		Insert_Node(t, x);
	}
}
void LNR(tree t)
{
	
	if (t != NULL)
	{
		LNR(t->pLeft);
		cout << t->info;
		LNR(t->pRight);
	}
}
void LRN(tree t)
{
	
	if (t != NULL)
	{
		LNR(t->pLeft);
		LNR(t->pRight);
		cout << t->info;
	}
}
void NLR(tree t)
{
	
	if (t != NULL)
	{
		cout << t->info;
		LNR(t->pLeft);
		LNR(t->pRight);
	}
}
void NRL(tree t)
{
	
	if (t != NULL)
	{
		cout << t->info;
		LNR(t->pRight);
		LNR(t->pLeft);
	}
}
void RNL(tree t)
{
	
	if (t != NULL)
	{
		LNR(t->pRight);
		cout << t->info;
		LNR(t->pLeft);
	}
}
void RLN(tree t)
{
	
	if (t != NULL)
	{
		LNR(t->pRight);
		LNR(t->pLeft);
		cout << t->info;
	}
}
node*Tim_Kiem(tree t, int x)
{
	if (t == NULL)
		return NULL;
	else 
	{
		if (t->info == x)
			return t;
		if (t->info > x)
			return Tim_Kiem(t->pLeft, x);
		return Tim_Kiem(t->pRight, x);
	}
}

void Delete(tree &);
node*Search_Stand_For(tree &, tree &);
int BST_Delete(tree &t, int x)
{
	if (t == NULL)
		return 0;
	if (t->info<x)
		return BST_Delete(t->pRight, x);
	if (x<t->info)
		return BST_Delete(t->pLeft, x);
	if (t->info == x)
		Delete(t);
	return 1;
}

void Delete(tree &t)
{
	node*temp = t;
	if (!t->pLeft && !t->pRight)
	{
		t = NULL;
		delete temp;
		return;
	}
	if (t->pLeft && !t->pRight)
	{
		t = t->pLeft;
		delete temp;
		return;
	}
	if (!t->pLeft && t->pRight)
	{
		t = t->pRight;
		delete temp;
		return;
	}
	temp = Search_Stand_For(t->pLeft, t);
	delete temp;
}
node*Search_Stand_For(tree&p, tree &q)
{
	if (p->pRight) 
		return Search_Stand_For( p->pRight, q); 
	//arrived
	node *temp = p;//p la phan tu the mang
	q->info = p->info; // q la node can xoa
	p = p->pLeft; 
	return temp;
}
int Dem_Node(tree t) 
{ 
	if (t == NULL) 
		return 0; 
	int a = Dem_Node(t->pLeft); 
	int b = Dem_Node(t->pRight); 
	return (a + b + 1); 
}
int Dem_Hai_Con(tree t) 
{
	if (t == NULL) 
		return 0; 
	int a = Dem_Hai_Con(t->pLeft); 
	int b = Dem_Hai_Con(t->pRight); 
	if (t->pLeft != NULL && t->pRight != NULL) 
		return a + b + 1; 
	return (a + b); 
}
int Dem_La(tree t) 
{ 
	if (t == NULL) 
		return 0; 
	int a = Dem_La(t->pLeft); 
	int b = Dem_La(t->pRight); 
	if (t->pLeft == NULL &&  t->pRight == NULL) 
		return a + b + 1; 
	return (a + b); 
}
int Chieu_Cao(tree t) 
{ 
	if (t == NULL) 
		return 0; 
	int a = Chieu_Cao(t->pLeft); 
	int b = Chieu_Cao(t->pRight); 
	if (a>b) 
		return a + 1; 
	return b + 1; 
}
int main()
{
	tree t;
	Input(t);
	cout << "a) In cay: \n";
	LNR(t); cout << endl;
	LRN(t); cout << endl;
	NLR(t); cout << endl;
	RNL(t); cout << endl;
	RLN(t); cout << endl;
	NRL(t); cout << endl;
	cout << "b) Tim nut co khoa bang 3: "<< Tim_Kiem(t, 3) <<endl;
	
	cout << "c) Xoa nut co khoa bang 4: " << BST_Delete(t, 4) << endl; 
	cout << "\t\tCon lai: "; LNR(t); cout << endl;
	
	cout << "d) Dem so nut trong cay: " << Dem_Node(t) << endl;
	
	cout << "e) Dem so nut co day du 2 con: "<< Dem_Hai_Con(t) << endl;
	
	cout << "f) Dem so nut la: " << Dem_La(t) << endl;
	
	cout << "g) Tinh chieu cao cua cay: " << Chieu_Cao(t) << endl;
	
	cout << "h) Ve cay nhi phan tim kiem ra man hinh: \n";

	system("pause");
	return 0;
}
