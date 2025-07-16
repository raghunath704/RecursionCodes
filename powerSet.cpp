#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void helper(string s, vector<string> &ans, string res, int i){
        if(i == s.size()){
            ans.push_back(res);
            return;
        }
        helper(s, ans, res, i+1);           // Don't include current character
        helper(s, ans, res + s[i], i+1);    // Include current character
    }
    
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        helper(s, ans, "", 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string test1 = "abc";
    cout << "Input: \"" << test1 << "\"" << endl;
    cout << "All possible subsequences:" << endl;
    
    vector<string> result1 = sol.AllPossibleStrings(test1);
    for(const string& str : result1) {
        if(str.empty()) {
            cout << "\"\" (empty string)" << endl;
        } else {
            cout << "\"" << str << "\"" << endl;
        }
    }
    
    cout << "\nTotal count: " << result1.size() << endl;
    
    // Test case 2
    cout << "\n" << string(40, '-') << "\n" << endl;
    
    string test2 = "ab";
    cout << "Input: \"" << test2 << "\"" << endl;
    cout << "All possible subsequences:" << endl;
    
    vector<string> result2 = sol.AllPossibleStrings(test2);
    for(const string& str : result2) {
        if(str.empty()) {
            cout << "\"\" (empty string)" << endl;
        } else {
            cout << "\"" << str << "\"" << endl;
        }
    }
    
    cout << "\nTotal count: " << result2.size() << endl;
    
    return 0;
}
