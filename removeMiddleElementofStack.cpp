#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    void solve(stack<int>& s, int k) {
        if (k == 1) {
            s.pop();
            return;
        }
        
        int temp = s.top();
        s.pop();
        solve(s, k - 1);
        s.push(temp);
    }
    
    void deleteMid(stack<int>& s) {
        if (s.empty()) return;
        
        int mid = floor((s.size() / 2) + 1);
        
        solve(s, mid);
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
    
    cout << "=== Testing Stack Middle Element Deletion ===" << endl << endl;
    
    cout << "Test Case 1: Odd number of elements (5 elements)" << endl;
    int arr1[] = {1, 2, 3, 4, 5};
    stack<int> s1 = createStack(arr1, 5);
    cout << "Original: ";
    printStack(s1);
    
    s1 = createStack(arr1, 5);
    solution.deleteMid(s1);
    cout << "After deleting middle: ";
    printStack(s1);
    cout << endl;
    
    cout << "Test Case 2: Even number of elements (4 elements)" << endl;
    int arr2[] = {10, 20, 30, 40};
    stack<int> s2 = createStack(arr2, 4);
    cout << "Original: ";
    printStack(s2);
    
    s2 = createStack(arr2, 4);
    solution.deleteMid(s2);
    cout << "After deleting middle: ";
    printStack(s2);
    cout << endl;
    
    cout << "Test Case 3: Single element" << endl;
    int arr3[] = {100};
    stack<int> s3 = createStack(arr3, 1);
    cout << "Original: ";
    printStack(s3);
    
    s3 = createStack(arr3, 1);
    solution.deleteMid(s3);
    cout << "After deleting middle: ";
    printStack(s3);
    cout << endl;
    
    cout << "Test Case 4: Two elements" << endl;
    int arr4[] = {50, 60};
    stack<int> s4 = createStack(arr4, 2);
    cout << "Original: ";
    printStack(s4);
    
    s4 = createStack(arr4, 2);
    solution.deleteMid(s4);
    cout << "After deleting middle: ";
    printStack(s4);
    cout << endl;
    
    cout << "Test Case 5: Three elements" << endl;
    int arr5[] = {7, 8, 9};
    stack<int> s5 = createStack(arr5, 3);
    cout << "Original: ";
    printStack(s5);
    
    s5 = createStack(arr5, 3);
    solution.deleteMid(s5);
    cout << "After deleting middle: ";
    printStack(s5);
    cout << endl;
    
    cout << "Test Case 6: Empty stack" << endl;
    stack<int> s6;
    cout << "Original: ";
    printStack(s6);
    
    solution.deleteMid(s6);
    cout << "After deleting middle: ";
    printStack(s6);
    
    return 0;
}
