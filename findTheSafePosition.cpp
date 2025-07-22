#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int helper(vector<int> &people, int ind, int k) {
        int s = people.size();
        if(s == 1) {
            return people[0];
        }
        ind = (ind + k - 1) % s;
        people.erase(people.begin() + ind);
        return helper(people, ind, k);
    }

    int safePos(int n, int k) {
        vector<int> people;
        for(int i = 0; i < n; i++) {
            people.push_back(i + 1);
        }
        return helper(people, 0, k);
    }
};

int main() {
    int n, k;
    cout << "Enter n and k (Separated by Space): ";
    cin >> n >> k;
    Solution sol;
    int safe_position = sol.safePos(n, k);
    cout << "Safe position: " << safe_position << endl;
    return 0;
}
