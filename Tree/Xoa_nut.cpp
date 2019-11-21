#include<iostream>

using namespace std;

struct BST_NODE
{
	int Key;
	int So_lan;
	struct BST_NODE * Left, * Right;
};

struct BST_TREE
{
	struct BST_NODE * pRoot;
};

struct BST_TREE t;

typedef BST_NODE * TREE;
	
void Init(TREE &t)
{
	t = NULL;
}


BST_NODE * GetNode(int x)
{
	BST_NODE * p = new BST_NODE;
	if (p == NULL)
		return NULL;
	p->Key = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}

void AddNode(TREE &t, int x)
{
	if (t !=NULL)
	{
		if (t->Key != x)
		{
			if (t->Key < x)
			{
				AddNode(t->Right, x);
			}
			else if (t->Key > x)
			{
				AddNode(t->Left, x);
			}
		}
		else
		{
			t->So_lan++;
		}
	}
	else
	{
		t = GetNode(x);	
		t->So_lan = 1;
	}
}

void ProcessTree(TREE t)
{
	if (t)
	{
		cout << "(" << t->Key << "(" << t->So_lan << ")" << ") ";
		ProcessTree(t->Left);
		ProcessTree(t->Right);
	}
}

bool isExist(TREE t, int x)     // tim nut co key x
{
	if (t)
	{
		if (t->Key == x) { return true; }
		if (t->Key > x) { return isExist(t->Left, x); }
		if (t->Key < x) { return isExist(t->Right, x); }
	}
	return NULL;
}

void Replace(TREE &X, TREE &Y) // NODE Y là node thế mạng cho node cần xóa - node này sẽ đảm nhận nhiệm vụ tìm ra node trái nhất(TÌM NODE TRÁI NHẤT CÂY CON PHẢI) hoặc phải nhất(TÌM NODE PHẢI NHẤT CỦA CÂY CON TRÁI)
{

	if (Y->Right != NULL)
	{
		Replace(X, Y->Right);// tìm ra node phải nhất ?
	}
	else // tìm ra được node phải nhất rồi nek..
	{
		X->Key = Y->Key; // cập nhật cái data của node cần xóa chính là data của node thế mạng
		X = Y; // cho node x(là node mà chúng ta sẽ đi xóa sau này) trỏ đến node thế mạng ==> ra khỏi hàm thì ta sẽ xóa node x
		Y = Y->Left; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) với node con của node thế mạng	
	}
}

void DelKey(TREE &t, int x)     
{
	if (!t) return;
	else if (t->Key > x)
		DelKey(t->Left, x);
	else if (t->Key < x)
		DelKey(t->Right, x);
	else if(t->Key == x)
	{
		if (t->So_lan > 1)
		{
			t->So_lan--;
			return;
		}
		else
		{
			BST_NODE * P = t;
			if (t->Left == NULL)
				t = t->Right;
			else if (t->Right == NULL)
				t = t->Left;
			else
			{
				Replace(P, t->Left);
			}
			delete P;
		}
	}
}


void main()
{
	TREE tree;
	Init(tree);
	AddNode(tree, 5); 
	AddNode(tree, 3);
	AddNode(tree, 6);
	AddNode(tree, 2);
	AddNode(tree, 4);
	AddNode(tree, 7);
	cout << "Cay ban dau: ";
	ProcessTree(tree);
	cout << endl;
	if (isExist(tree, 4))
	{
		DelKey(tree, 4);
	}
	else cout << "Khong co phan tu nay trong cay!!" << endl;
	cout << "Cay sau khi xoa(4): ";
	ProcessTree(tree);


	t.pRoot = tree;
	system("pause");
}