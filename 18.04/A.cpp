#include <iostream>
#include <stack>
using namespace std;
class MyStack {
private:
    stack<int> s;
    int maxEle;
public:
    void getMax()
    {
        if (s.empty()){ cout << "Stack is empty" << endl; }
        else { cout << "Maximum in the stack is: " << maxEle << "\n"; }
    }

    void peek()
    {
        if (s.empty()) { cout << "Stack is empty "; return; }
        int t = s.top();
        cout << "Top Most  is: ";
        (t > maxEle) ? cout << maxEle : cout << t;
    }

    void pop()
    {
        if (s.empty()) { cout << "Stack is empty" << endl; return; }
        cout << "Top Most Removed: ";
        int t = s.top();
        s.pop();
        if (t > maxEle) { cout << maxEle << "\n"; maxEle = 2 * maxEle - t; }
        else { cout << t << endl; }
    }

    void push(int x)
    {
        if (s.empty()) {
            maxEle = x;
            s.push(x);
            cout << "Inserted: " << x << "\n";
            return;
        }
        if (x > maxEle) { s.push(2 * x - maxEle); maxEle = x; }
        else { s.push(x); }
        cout << "Inserted: " << x << "\n";
    }
};

int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMax();
    s.push(7);
    s.push(19);
    s.getMax();
    //s.pop();
    //s.getMax();
    //s.pop();
    //s.peek();

    return 0;
}