#include <iostream>
#include <vector>
#include <string>
#include <cctype> 

using namespace std;

void helper(string s, vector<string> &ans, string res, int i) {
    if (i == s.size()) {
        ans.push_back(res);
        return;
    }
    helper(s, ans, res + (char)tolower(s[i]), i + 1);
    helper(s, ans, res + (char)toupper(s[i]), i + 1);
}

vector<string> permutation(string s) {
    vector<string> ans;
    if (s.empty()) return ans;
    helper(s, ans, "", 0);
    return ans;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    vector<string> results = permutation(input);

    cout << "Generated permutations:\n";
    for (const string &str : results) {
        cout << str << endl;
    }

    return 0;
}
