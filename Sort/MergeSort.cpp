// MergeSort.cpp : Defines the entry point for the console application.
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

void Merge(int a[], int start, int mid, int end)
{
	int first = start,
		next = mid + 1;
	int *Arr = new int[end - start + 1],
		k = 0;
	for (int i = start; i <= end; i++)
	{
		if (first > mid)
			Arr[k++] = a[next++];
		else if (next > end)
			Arr[k++] = a[first++];
		else if (a[first] < a[next])
			Arr[k++] = a[first++];
		else Arr[k++] = a[next++];
	}
	for (int i = 0; i < k; i++)
	{
		a[start++] = Arr[i];
	}
	Arr = NULL;
	delete[] Arr;
}

void Merge_Sort(int a[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Merge_Sort(a, start, mid);
		Merge_Sort(a, mid + 1, end);
		Merge(a, start, mid, end);
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
	Merge_Sort(a,0, n-1);
	XuatMang(a, n);
	system("pause");
    return 0;
}

