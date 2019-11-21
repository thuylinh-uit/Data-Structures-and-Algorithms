// All.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

void hoanvi(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void InterChange(int a[], int n)
{
	for (int i = 0; i<n - 1; i++)
		for (int j = i + 1; j<n; j++)
			if (a[i] > a[j])
				hoanvi(a[i], a[j]);
}
void Bubble(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j >= i; j--)
			if (a[j] < a[j - 1])
				hoanvi(a[j], a[j - 1]);
}
void Selection(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int lc = i;
		for (int j = i; j < n; j++)
			if (a[j] < a[lc])
				lc = j;
		hoanvi(a[i], a[lc]);
	}
}
void Insertion(int a[], int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		int x = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > x; j--)
		{
			a[j + 1] = a[j];
			a[j + 1] = x;
		}
	}
}
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

int max_2(int a[], int x, int y)
{
	if (a[x] > a[y])
		return x;
	return y;
}

int max_3(int a[], int x, int y, int z)
{
	int k = max(max(a[x], a[y]), a[z]);
	if (k == a[x])
		return x;
	if (k == a[y])
		return y;
	return z;
}

void Heap(int a[], int n)
{
	while (n > 0)
	{
		int left, right, Max;
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			left = 2 * i + 1;
			right = 2 * i + 2;
			if (right >= n)
			{
				Max = max_2(a, i, left);
				hoanvi(a[i], a[Max]);
			}
			else
			{
				Max = max_3(a, i, left, right);
				hoanvi(a[i], a[Max]);
			}
		}
		hoanvi(a[0], a[n - 1]);
		n--;
	}
}


void Input(int a[], int &n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 200;
}
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int a[100];
	int n;
	n = 10 + rand() % 10;
	clock_t start = clock();

	Input(a, n);
	cout << "Cac so ban dau:" << endl;
	Output(a, n);

	Selection(a, n);
	cout <<"Time: "<< (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	cout << "SelectionSort:" << endl;
	Output(a, n);

	Bubble(a, n);
	cout <<"Time: "<< (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	cout << "BubbleSort:" << endl;
	Output(a, n);

	InterChange(a, n);
	cout << "Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	cout << "InterChangeSort:" << endl;
	Output(a, n);

	Insertion(a, n);
	cout << "Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	cout << "InsertionSort:" << endl;
	Output(a, n);

	Merge_Sort (a, 0, n - 1);
	cout << "Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	cout << "MergeSort:" << endl;
	Output(a, n);

	QuickSort(a, n);
	cout << "Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	cout << "QuickSort:" << endl;
	Output(a, n);


	Heap(a, n);
	cout << "Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
	cout << "HeapSort:" << endl;
	Output(a, n);
	
	system("pause");
	return 0;
}

