#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        if (s.empty()) return ans;
        helper(ans, s, "", 0);
        return ans;
    }

    void helper(vector<string>& ans, string s, string res, int i) {
        if (i == s.size()) {
            ans.push_back(res);
            return;
        }
        if (isdigit(s[i])) {
            helper(ans, s, res + s[i], i + 1);
            return;
        }
        
        helper(ans, s, res + (char)tolower(s[i]), i + 1);
        helper(ans, s, res + (char)toupper(s[i]), i + 1);
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string: ";
    cin >> input;
    vector<string> result = sol.letterCasePermutation(input);
    cout << "Letter case permutations:\n";
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}
