#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void helper(vector<string>& ans, string s, int i, string res) {
        if (i == s.size()) {
            ans.push_back(res);
            return;
        }
        helper(ans, s, i + 1, res + s[i]);
        helper(ans, s, i + 1, res + " " + s[i]);
    }

    vector<string> permutation(string s) {
        vector<string> ans;
        string res = s.substr(0, 1);
        helper(ans, s, 1, res);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string input = "ABCD";

    Solution sol;
    vector<string> result = sol.permutation(input);

    for (const string& str : result) {
        cout << "(" << str << ")";
    }
    cout << endl;

    return 0;
}
