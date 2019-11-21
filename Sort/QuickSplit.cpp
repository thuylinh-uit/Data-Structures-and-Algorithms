// QuickSplit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

void split(int a[], int n, 
	       int x,
	       int b[], int &k, 
	       int c[], int &l)
{
	k = l = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < x)
			b[k++] = a[i];
		else
		    if (a[i] > x)
		        c[l++] = a[i];
	}
}

void QuickSort(int a[], int n)
{
	if (n <= 1)
		return;
	int b[100]; int k;
	int c[100]; int l;
	int TrongTai = a[0];
	split(a, n, TrongTai, b, k, c, l);
	QuickSort(b, k);
	QuickSort(c, l);
	for (int i = 0; i < k; i++)
		a[i] = b[i];
	for (int i = 0; i < n - k - l; i++)
		a[k + i] = TrongTai;
	for (int i = 0; i < l; i++)
		a[k + (n - k - l) + i] = c[i];
}

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int a[50];
	cout << "Nhap mang: ";
	NhapMang(a, n);
	QuickSort(a, n);
	XuatMang(a, n);
	system("pause");
	return 0;
}



