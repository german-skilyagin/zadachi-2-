#include <iostream>
#include <stack>
using namespace std;
class VersionedStack {
private:
    stack<int> data_stack;
    stack<int> version_stack;
    int current_version;
public:
    VersionedStack() {
        current_version = 0;
        version_stack.push(current_version);
    }

    void Push(int x) {
        data_stack.push(x);
        current_version++;
        version_stack.push(current_version);
    }

    void Pop() {
        data_stack.pop();
        current_version++;
        version_stack.push(current_version);
    }

    void Rollback(int version) {
        while (version_stack.top() > version) { version_stack.pop(); current_version--; }
    }

    void Forget() {
        data_stack = stack<int>();
        version_stack = stack<int>();
        current_version = 0;
        version_stack.push(current_version);
    }

    int Top() { return data_stack.top(); }
};

int main() {
    VersionedStack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    cout << stack.Top() << endl;
    stack.Rollback(1);
    cout << stack.Top() << endl;
    stack.Forget();
    stack.Push(4);
    cout << stack.Top() << endl;
    return 0;
}