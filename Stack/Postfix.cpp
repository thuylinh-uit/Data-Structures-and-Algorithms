#include<iostream>
#include<string>

using namespace std;

struct node
{
	char token;
	node * pNext;
};

struct stack
{
	node * top;
};

void Init(stack &s)
{
	s.top = NULL;
}

node * GetNode(char t)
{
	node * p = new node;
	if (p == NULL)
		return NULL;
	p->token = t;
	p->pNext = NULL;
}

void Push(stack &s, char t)
{
	node * p = GetNode(t);
	if (s.top == NULL)
		s.top = p;
	else
	{
		p->pNext = s.top;
		s.top = p;
	}
}

node * Pop(stack &s)
{
	if (s.top == NULL)
		return NULL;
	node * t = s.top;
	s.top = s.top->pNext;
	t->pNext = NULL;
	return t;
}

char Peak(stack s)
{
	return s.top->token;
}

int CheckPriority(char c)
{
	if (c == '(')
		return 0;
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/' || c == '%')
		return 2;
	if (c == '^')
		return 3;
}

void Calculate(string s)
{
	int solu;
	stack st;
	Init(st);
	string hauto = "";
	for (int i = 0; i < s.length(); i++)
	{
		char token = s[i];
		if (token != ' ')
		{
			if (token - '0' >= 0 && token - '0' <= 9 || isalpha(token))
				//trường hợp biểu thức có số (1).
				hauto += token;//đẩy vào string.
			else //trường hợp gặp toán tử hoặc dấu mở ngoặc.
			{
				if (token == '(') 
					//trường hợp gặp dấu mở ngoặc 
					//có nghĩa là xuất hiện ưu tiên (2).
					Push(st, token); //Đẩy dấu vào stack.
				else // sau khi đẩy dấu vào stack ta có thể gặp 
					//số ở trường hợp (1),
					 // xét các trường hợp gặp toán tử hay dấu đóng ngoặc
				{
					if (token == ')')  
						//Gặp dấu đóng ngoặc sẽ cho đẩy các dấu ra ngoài
					{
						while (st.top->token != '(')
						{
							hauto += ' '; 
							hauto += Pop(st)->token;
						}
						Pop(st); //Đẩy dấu mở ngoặc 
						//để kết thúc trường hợp (2).
					}	
					else //Gặp toán tử
					{
						if (st.top == NULL) //Kiểm tra stack 
							//có tồn tại dấu hay không
						{
							hauto += ' ';
							Push(st, token);
						}
						else
						{ //khi stack có dấu, ta xét mức độ ưu tiên 
						if (CheckPriority(token) <= CheckPriority(Peak(st)))
						//Khi xác nhận token từ chuỗi có mức độ ưu tiên 
								//thấp hơn từ stack
						//Ta đẩy toán tử từ stack vào chuỗi 
								//và thêm token vào stack
							{
								hauto += ' ';
								hauto += Pop(st)->token;
								Push(st, token);
							}
							else 
						//Ngược lại với trên, ta chỉ đẩy toán tử 
							//vào stack khi thấy mức độ ưu tiên cao hơn
							{
								hauto += ' ';
								Push(st, token);
							}
						}
					}
				}
			}
		}
	}
	while (st.top)
	{
		hauto += ' ';
		hauto += Pop(st)->token;
	}
	cout << "Bieu thuc hau to: " << hauto << endl;
}
void main()
{
	string s;
	cout << "Nhap bieu thuc: ";
	getline(cin, s);
	Calculate(s);

	system("pause");
}