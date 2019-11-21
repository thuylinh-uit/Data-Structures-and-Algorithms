#include<iostream>

using namespace std;

struct node
{
	int data;
	node * pNext;
	node * pPrev;
};
struct list
{
	node * pHead;
	node * pTail;
};
bool isEmpty(list l)
{
	return (l.pHead == NULL);
}
void Init(list & l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node * GetNode(int x)
{
	node * p = new node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}
void AddHead(list&l, node * p)
{
	if (isEmpty(l))
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p; 
	}
}
void AddTail(list&l, node * p)
{
	if (isEmpty(l))
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}
void InsertAfter(list&l, node * pos, node * val)
// pos la vi tri cua l.pHead
// val la gia tri them vao sau
{
	if (isEmpty(l))
		l.pHead = l.pTail = val;
	else
	{
		pos->pNext->pPrev = val;
		// noi node Prev cua node Next(cua pos) la value
		//co nghia la node lien trc cua lien sau la value

		val->pNext = pos->pNext;// node Next cua Val la node Next cua pos

		pos->pNext = val;// sau khi noi cac Prev va Next ta noi pos -> val


		val->pPrev = pos;// va noi prev cho val
	}
}
node * GetX(list & l, node * X)
{
	if (isEmpty(l))
		return NULL;
	node * p;
	if (l.pHead->data == X->data)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		l.pHead->pPrev = NULL;
		p->pNext = NULL;
		return p;
	}
	if (l.pTail->data == X->data)
	{
		p = l.pTail;
		l.pTail = l.pTail->pPrev;
		l.pTail->pNext = NULL;
		p->pPrev = NULL;
		return p;
	}
	while (l.pHead->pNext = l.pTail)
	{
		if (l.pHead->data == X->data)
		{
			p = l.pHead;
			node * temp = l.pHead->pNext;
			l.pHead = l.pHead->pPrev;
			temp->pPrev = l.pHead;
			l.pHead->pNext = temp;
			p->pNext = NULL;
			return p;
		}
		l.pHead = l.pHead->pNext;
	}
}
void Output(list l)
{
	if (isEmpty(l))
		return;
	while (l.pHead)
	{
		cout << "<" << l.pHead->data << "> ";
		l.pHead = l.pHead->pNext;
	}
}
void Input(list & l)
{
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	if (n == 0)
		return;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri " << i + 1 << " :";
		unsigned int x;
		cin >> x;
		node * p = GetNode(x);
		cout << "Danh tam thoi: ";
		if (isEmpty(l)) //trường hợp list rỗng
		{
			AddTail(l, p);
			Output(l);
			cout << endl;
		}
		else if (l.pHead->data > p->data) 
			//trường hợp có 1 node hoặc giá trị l.pHead lớn hơn X
		{
			AddHead(l, p);
			Output(l);
			cout << endl;
		}
		else if (l.pTail->data < p->data) 
			//trường hợp có 1 node hoặc giá trị l.Tail  bé hơn giá trị X
		{
			AddTail(l, p);
			Output(l);
			cout << endl;
		}
		else
		{
			node * temp = l.pHead;
			while (temp) 
				//Trường hợp list có 2 node trở lên mà k có 2 trường hợp đặc biệt trên
			{
				if (temp->pNext->data > p->data)
				{
					InsertAfter(l, temp, p);
					Output(l);
					cout << endl;
					break;
				}
				temp = temp->pNext;
			}
		}
	}
}

void main()
{
	list l;
	Init(l);
	Input(l);
	cout << "\nDanh sach chinh thuc: ";
	Output(l);

	system("pause");
}