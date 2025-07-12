#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        int last = nums[n-1];
        nums.pop_back();
        nums = sortArray(nums);
        add(nums, last);
        return nums;
    }
    
    void add(vector<int>& nums, int last) {
        int n = nums.size();
        if (n < 1 || nums[n-1] <= last) {
            nums.push_back(last);
            return;
        }
        int temp = nums[n-1];
        nums.pop_back();
        add(nums, last);
        nums.push_back(temp);
    }
};


void printArray(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums;
    
    if (n > 0) {
        nums.resize(n);
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
    }
    
    cout << "\nOriginal array: ";
    printArray(nums);
    
    vector<int> sorted = solution.sortArray(nums);
    
    cout << "Sorted array: ";
    printArray(sorted);
    
    return 0;
}