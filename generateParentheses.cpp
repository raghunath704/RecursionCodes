#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) return ans;

        helper(n, ans, "", n, n);
        return ans;
    }

    void helper(int n, vector<string> &ans, string res, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(res);
            return;
        }
        if (open == close) {
            helper(n, ans, res + "(", open - 1, close);
            return;
        }
        if (open > 0) helper(n, ans, res + "(", open - 1, close);
        if (close > 0) helper(n, ans, res + ")", open, close - 1);
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    vector<string> result = sol.generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ":\n";
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
