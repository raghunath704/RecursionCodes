#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void Helper(vector<int> &arr, int n, vector<vector<int>> &ans, vector<int>&res, int i) {
        if (i == n) {
            ans.push_back(res);
            return;
        }
        
        res.push_back(arr[i]);
        Helper(arr, n, ans, res, i + 1);
        res.pop_back();
        
        while (i < n - 1 && arr[i] == arr[i + 1]) {
            i++;
        }
        
        Helper(arr, n, ans, res, i + 1);
    }
    
    vector<vector<int>> AllSubsets(vector<int> arr, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(arr.begin(), arr.end());
        Helper(arr, n, ans, res, 0);
        return ans;
    }
};

void printSubsets(const vector<vector<int>>& subsets) {
    cout << "Unique Subsets: " << subsets.size() << endl;
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << " }" << endl;
    }
}

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {1, 2, 2};
    cout << "Test 1: {1, 2, 2}" << endl;
    auto result1 = sol.AllSubsets(arr1, 3);
    printSubsets(result1);
    
    cout << "\n" << string(30, '-') << "\n" << endl;
    
    vector<int> arr2 = {4, 4, 4, 1, 4};
    cout << "Test 2: {4, 4, 4, 1, 4}" << endl;
    auto result2 = sol.AllSubsets(arr2, 5);
    printSubsets(result2);
    
    return 0;
}
