#include <iostream>
#include <stack>
using namespace std;

class SortedStack {
public:
    stack<int> s;
    void sort();
};

void add(stack<int>& s, int n) {
    if (s.empty() || s.top() <= n) {
        s.push(n);
        return;
    }
    int temp = s.top();
    s.pop();
    add(s, n);
    s.push(temp);
}

void SortedStack::sort() {
    if (s.size() <= 1) return;
    int topel = s.top();
    s.pop();
    sort();
    add(s, topel);
}

void printStack(stack<int> s) {
    cout << "Stack (top to bottom): ";
    if (s.empty()) {
        cout << "empty" << endl;
        return;
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    SortedStack sortedStack;
    
    sortedStack.s.push(30);
    sortedStack.s.push(-5);
    sortedStack.s.push(18);
    sortedStack.s.push(14);
    sortedStack.s.push(-3);
    sortedStack.s.push(25);
    sortedStack.s.push(10);
    
    cout << "Original ";
    printStack(sortedStack.s);
    
    sortedStack.sort();
    
    cout << "Sorted ";
    printStack(sortedStack.s);
    
    return 0;
}
