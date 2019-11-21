// RadixSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

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

void Radix_Sort(int *a, int n)
{
	int i, at = 1, s[10], t[100], h = 1, max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	while (max / h > 0)
	{
		for (i = 0; i < 10; i++)
			s[i] = 0;
		for (i = 0; i < n; i++)
			s[a[i] / h % 10] ++;
		for (i = 1; i < 10; i++)
			s[i] += s[i - 1];
		if (at == 1)
		{
			for (i = n - 1; i >= 0; i--)
				t[--s[a[i] / h % 10]] = a[i];
		}
		else for (i = n - 1; i >= 0; i--)
				a[--s[t[i] / h % 10]] = t[i];
		at = -at;
		h *= 10;
	}
	if (at == -1)
		for (i = 0; i < n; i++)
			a[i] = t[i];
}


int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int a[50];
	cout << "Nhap mang: ";
	NhapMang(a, n);
	Radix_Sort(a,n);
	XuatMang(a, n);
	system("pause");
    return 0;
}

