#include <iostream>
using namespace std;

struct stack
{
	int n;
	int a[100];
};
void Init(stack &st)
{
	st.n = 0;
}
int IsEmpty(stack st)
{
	if (st.n == 0)
		return 1;
	return 0;
}
int IsFull(stack st)
{
	if (st.n == 100)
		return 1;
	return 0;
}
void Push(stack &st, int x)
{
	st.a[st.n] = x;
	st.n++;
}
int Pop(stack &st)
{
	int x = st.a[st.n - 1];
	st.n--;
	return x;
}
void Input(stack &st)
{
	Init(st);
	cout << "Nhap so phan tu cua stack: "; cin >> st.n;
	
	cout << "Nhap cac phan tu cua stack: ";
	for (int i = 0; i < st.n; i++)
		cin >> st.a[i];
}
void Output(stack st)
{
	cout << "Stack: ";
	for (int i = 0; i < st.n; i++)
	{
		cout << st.a[i] << " ";
	}
	cout << "\n\n";
}
int main()
{
	stack st;
	Input(st);
	Output(st);

	cout << "Push 3: \n";
	Push(st, 3);
	Output(st);

	cout << "Pop: \n";
	Pop(st);
	Output(st);
	system("pause");
	return 0;
}