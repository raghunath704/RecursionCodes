#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void add(stack<int> &s, int a) {
        if (s.empty()) {
            s.push(a);
            return;
        }
        int temp = s.top();
        s.pop();
        add(s, a);
        s.push(temp);
    }
    
    void Reverse(stack<int> &s) {
        if (s.size() <= 1) {
            return;
        }
        int temp = s.top();
        s.pop();
        Reverse(s);
        add(s, temp);
    }
};

void printStack(stack<int> s) {
    if (s.empty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    cout << "Stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

stack<int> createStack(int arr[], int size) {
    stack<int> s;
    for (int i = 0; i < size; i++) {
        s.push(arr[i]);
    }
    return s;
}

int main() {
    Solution solution;
    
    cout << "=== Testing Stack Reverse ===" << endl << endl;
    
    cout << "Test Case 1: Multiple elements" << endl;
    int arr1[] = {1, 2, 3, 4, 5};
    stack<int> s1 = createStack(arr1, 5);
    cout << "Original: ";
    printStack(s1);
    
    s1 = createStack(arr1, 5);
    solution.Reverse(s1);
    cout << "After reverse: ";
    printStack(s1);
    cout << endl;
    
    cout << "Test Case 2: Two elements" << endl;
    int arr2[] = {10, 20};
    stack<int> s2 = createStack(arr2, 2);
    cout << "Original: ";
    printStack(s2);
    
    s2 = createStack(arr2, 2);
    solution.Reverse(s2);
    cout << "After reverse: ";
    printStack(s2);
    cout << endl;
    
    cout << "Test Case 3: Single element" << endl;
    int arr3[] = {100};
    stack<int> s3 = createStack(arr3, 1);
    cout << "Original: ";
    printStack(s3);
    
    s3 = createStack(arr3, 1);
    solution.Reverse(s3);
    cout << "After reverse: ";
    printStack(s3);
    cout << endl;
    
    cout << "Test Case 4: Empty stack" << endl;
    stack<int> s4;
    cout << "Original: ";
    printStack(s4);
    
    solution.Reverse(s4);
    cout << "After reverse: ";
    printStack(s4);
    cout << endl;
    
    cout << "Test Case 5: Larger stack" << endl;
    int arr5[] = {7, 14, 21, 28, 35, 42};
    stack<int> s5 = createStack(arr5, 6);
    cout << "Original: ";
    printStack(s5);
    
    s5 = createStack(arr5, 6);
    solution.Reverse(s5);
    cout << "After reverse: ";
    printStack(s5);
    
    return 0;
}
