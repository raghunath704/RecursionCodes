#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    void helper(vector<string>&ans, int n, string res, int one, int zero){
        if(res.size()==n){
            ans.push_back(res);
            return;
        }
        helper(ans, n, res + "1", one + 1, zero);
        if(one > zero){
            helper(ans, n, res + "0", one, zero + 1);
        }
    }

    vector<string> NBitBinary(int n) {
        vector<string> ans;
        string res = "1";
        helper(ans, n, res, 1, 0);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    vector<string> result = sol.NBitBinary(n);

    cout << "N-bit binary numbers with more 1s than 0s in every prefix:\n";
    for(const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
