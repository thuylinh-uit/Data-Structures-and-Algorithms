/*
Viet chuong trinh thuc hien cac yeu cau sau tren danh sach lien ket kep vong cac nhan vien:
	a. Khai bao cau truc du lieu cua mot danh sach lien ket don cac nhan vien 
		Biet rang thong tin cua mot nhan vien bao gom:
			ho ten (30 ky tu)
			ngay sinh (kieu ngay)
			luong (so thuc)
			gioi tinh (0. Nu 1. Nam)
	b. Cai dat tat ca cac thao tac co ban cho danh sach lien ket cac nhan vien
	c. Liet ke cac nhan vien tren 40 tuoi trong danh sach
	d. Dem so luong nhan vien co luong lon hon 1 000 000 dong trong danh sach
	e. Viet ham sap xep cac nhan vien giam dan theo nam sinh khong quan tam ngay va thang sinh
*/
#include<iostream>
#include<stdio.h>
#include <string>
#include<algorithm>
using namespace std;
//khai bao danh sach lien ket kep vong
struct date {
	int ngay, thang, nam;
};
typedef date DATE;

struct nhanvien {
	string HoTen;
	DATE NS;
	double Luong;
	int GioiTinh;
};
typedef nhanvien NHANVIEN;

struct node {
	NHANVIEN info;
	node* pNext;
	node* pPrev;
};
typedef node NODE;

struct list {
	NODE *pHead;
	NODE *pTail;
};
typedef list LIST;
///--------------------------
//ham khoi tao danh sach lien ket
void Init(LIST &l) {
	l.pHead = l.pTail = NULL;
}

//--------------
NODE* GetNode(NHANVIEN x) {
	NODE *p = new NODE;
	if (p == NULL) return NULL;
	p->info = x;
	p->pPrev = NULL;
	p->pNext = NULL;
	return p;
}
// Them vao cuoi danh sach
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
	NHANVIEN A;
	cin.ignore();
	cout << "           nhap Ho va ten: ";
	getline(cin,A.HoTen);
	cout << "           nhap ngay_thang_nam sinh: ";
	cin >> A.NS.ngay >> A.NS.thang >> A.NS.nam;
	cout << "           nhap luong: ";
	cin >> A.Luong;
	cout << "           nhap gioi tinh (0.nu, 1.nam): ";
	cin >> A.GioiTinh;
	NODE *p = GetNode(A);
	AddTail(l, p);
}
void Input(LIST &l)
{
	cout << "Nhap so luong nhan vien trong danh sach: ";
	int n;
	cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++) {
		cout << "\n--Nhap nhan vien thu " << i << ":" << endl;
		Nhap(l);
	}
}

void XuatNV(NODE *p) {
	cout << "Ho va ten:" << p->info.HoTen << endl;
	cout << "Ngay Sinh:" << p->info.NS.ngay << "/" << p->info.NS.thang << "/" << p->info.NS.nam << endl;
	cout << "Luong:" << p->info.Luong << endl;
	cout << "Gioi tinh:";
	if (p->info.GioiTinh == 0) cout << "Nu";
	else cout << "Nam";
	cout << endl << endl;
}
//------Liet ke nhan vien lon hon 40 tuoi
void Tren40(LIST l)
{
	cout << "\nCac nhan vien tren 40 tuoi la:" << endl;
	NODE *p = l.pHead;
	do {
		if (2018 - p->info.NS.nam>40)
			XuatNV(p);
		p = p->pNext;
	} while (p != l.pHead);
}
//-----Dem so luong lon hon 1 trieu;
void Hon1tr(LIST l)
{
	NODE*p = l.pHead;
	int dem = 0;
	do {
		if (p->info.Luong>1000000)	++dem;
		p = p->pNext;
	} while (p != l.pHead);
	cout << "\nso nhan vien luong hon 1 trieu la:" << dem << endl;
}

void sortL(list &l) {
	NODE *p1 = l.pHead;
	do {
		NODE *p2 = p1->pNext;
		do {
			if (p1->info.NS.nam<p2->info.NS.nam) {
				swap(p1->info, p2->info);
			}
			p2 = p2->pNext;
		} while (p2 != l.pHead);
		p1 = p1->pNext;
	} while (p1 != l.pHead);
}
void Output(LIST l)
{
	NODE*p = l.pHead;
	do {
		XuatNV(p);
		p = p->pNext;
	} while (p != l.pHead);
}

int main() 
{
	LIST l;
	Input(l);
	Tren40(l);
	Hon1tr(l);
	cout << "\n\nDanh sach sau khi sap xep:" << endl;
	sortL(l);
	Output(l);
	system("pause");
	return 0;
}
