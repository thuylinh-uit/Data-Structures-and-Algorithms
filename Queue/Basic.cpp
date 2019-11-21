#include <iostream>
using namespace std;

struct queue
{
	int n;
	int a[100];
};
void Init(queue &que)
{
	que.n = 0;
}
int IsEmpty(queue que)
{
	if (que.n == 0)
		return 1;
	return 0;
}
int IsFull(queue que)
{
	if (que.n == 100)
		return 1;
	return 0;
}
void Enque(queue &que,int x)
{
	que.a[que.n] = x;
	que.n++;
}
int Deque(queue &que)
{
	int x = que.a[0];
	for (int i = 0; i <= que.n-2; i++)
		que.a[i] = que.a[i + 1];
	que.n--;
	return x;
}
void Input(queue &que)
{
	Init(que);
	cout << "Nhap so phan tu cua queue: "; cin >> que.n;
	cout << "Nhap cac phan tu cua queue: ";
	for (int i = 0; i < que.n; i++)
		cin >> que.a[i];
}
void Output(queue que)
{
	for (int i = 0; i < que.n; i++)
		cout << que.a[i] << " ";
	cout << "\n\n";
}
int main()
{
	queue que;
	Input(que);
	Output(que);

	cout << "Enque 4: \n";
	Enque(que, 4);
	Output(que);

	cout << "Deque: \n";
	Deque(que);
	Output(que);

	system("pause");
	return 0;
}