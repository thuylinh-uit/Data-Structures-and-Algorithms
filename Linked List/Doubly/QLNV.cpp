#include<iostream>
#include<string>

using namespace std;

struct NS
{
	int maso;
	string hoten;
	int thamnien;
	float hesoluong; 
	float luongcoban; 
};
struct node
{
	NS data;
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
node * GetNode(NS x)
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
void InputNS(NS & x) //Nhập thông tin 1 nhân sự
{
	cout << "Nhap ma so: ";
	cin >> x.maso;
	cin.ignore();
	cout << "Nhap ho va ten: ";
	getline(cin, x.hoten);
	cout << "Nhap so tham nien cong tac: ";
	cin >> x.thamnien;
	cout << "Nhap he so luong: ";
	cin >> x.hesoluong;
	cout << "Nhap luong co ban (dv trieu): ";
	cin >> x.luongcoban;
} 
float Salary(NS & X)// Tính lương mỗi NS
{
	return X.hesoluong*X.luongcoban;
} 
void OutputNS(NS x)//Xuất 1 nhân sự
{
	cout << "Ma so: " << x.maso;
	cout << "Ho va ten: " << x.hoten;
	cout << "Tham nien cong tac: " << x.thamnien;
	cout << "Luong: " << Salary(x) << " trieu";
} 
void Input(list &l)
{
	int n;
	cout << "Nhap so nhan su: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		NS X;
		InputNS(X);
		node * p = GetNode(X);
		AddTail(l, p);
	}
}
void FilterBySeniority(list &l) //Sắp xếp nhân viên giảm dần theo thâm niên bằng quicksort
{
	node *tag , *p;
	list l1, l2;
	if (l.pHead == NULL) return;
	else
	{
		if (l.pHead == l.pTail) return;
		Init(l1);
		Init(l2);
		tag = l.pHead; 
		l.pHead = l.pHead->pNext;
		while (l.pHead)
		{
			p = l.pHead;
			l.pHead = l.pHead->pNext;
			p->pNext = NULL;
			if (p->data.thamnien >= tag->data.thamnien)
				AddTail(l1, p);
			else
				AddTail(l2, p);
		}
		FilterBySeniority(l1);
		FilterBySeniority(l2);
		if (l1.pHead != NULL)
		{
			l.pHead = l1.pHead;
			l1.pTail->pNext = tag;
		}
		else
			l.pHead = tag;
		if (l2.pHead != NULL)
		{
			tag->pNext = l2.pHead;
			l.pTail = l2.pTail;
		}
		else
			l.pTail = tag;
	}
} 
float AverageSalary(list l)// Tính lương trung bình của tất cả nhân viên
{
	float avgsal = 0;
	int n = 1;
	while (l.pHead)
	{
		avgsal += Salary(l.pHead->data);
		n++;
		l.pHead = l.pHead->pNext;
	}
	return avgsal = avgsal / n;
} 
node * BestSal_ShortestSen(list l)
{
	node * p = l.pHead;
	node * temp = l.pHead;
	temp = temp->pNext;
	while (temp)
	{
		if (Salary(temp->data) >= Salary(p->data) && (temp->data.thamnien <= p->data.thamnien))
			p = temp;
		temp = temp->pNext;
	}

	return p;
}
void OutputFilter(list l) 
{
	list l1, l2, ltemp;
	Init(l1);
	Init(l2); 
	int dem1 = 1, dem2 = 1;
	while (l.pHead)
	{
		if(l.pHead->data >=)
	}

}