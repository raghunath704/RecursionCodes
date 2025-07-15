#include <iostream>
#include <cmath>

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1) return 0;
        int mid = pow(2, n - 1) / 2;
        if (k <= mid) return kthGrammar(n - 1, k);
        return !kthGrammar(n - 1, k - mid);
    }
};

int main() {
    Solution sol;
    int n, k;

    std::cout << "Enter value of n: ";
    std::cin >> n;
    std::cout << "Enter value of k: ";
    std::cin >> k;

    int result = sol.kthGrammar(n, k);
    std::cout << "The " << k << "-th symbol in row " << n << " is: " << result << std::endl;

    return 0;
}
