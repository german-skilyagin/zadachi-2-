#include <iostream>
#include <stack>
using namespace std;

class queue
{
	stack<int> s1;
	stack<int> s2;
public:
	void push(int n)
	{
		s1.push(n);
	}
	void pop()
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	void print()
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		while (!s2.empty())
		{
			cout << s2.top() << ' ';
			s1.push(s2.top());
			s2.pop();
		}
	}
};

int main()
{
	queue q;
	q.push(0);
	q.push(1);
	q.push(2);
	q.print();
	cout << endl;
	q.pop();
	q.print();
	cout << endl;
	q.pop();
	q.print();
	cout << endl;
	return 0;
}