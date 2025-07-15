#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        return n==0? 0:towerOfHanoi(n-1,from,aux,to)+towerOfHanoi(n-1,aux,to,from)+1;
    }
};

void printTowerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    
    printTowerOfHanoi(n-1, from, aux, to);
    
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    
    printTowerOfHanoi(n-1, aux, to, from);
}

int main() {
    Solution solution;
    
    cout << "=== Tower of Hanoi - Number of Moves ===\n" << endl;
    
    // Test cases
    vector<int> testCases = {0, 1, 2, 3, 4, 5, 6};
    
    for (int n : testCases) {
        int moves = solution.towerOfHanoi(n, 1, 3, 2);
        int expectedMoves = (n == 0) ? 0 : pow(2, n) - 1;
        
        cout << "n = " << n << " disks:" << endl;
        cout << "  Moves required: " << moves << endl;
        cout << "  Expected (2^n - 1): " << expectedMoves << endl;
        cout << "  Match: " << (moves == expectedMoves ? "✓" : "✗") << endl;
        cout << endl;
    }
    
    // Demonstrate actual moves for small cases
    cout << "\n=== Actual Moves Demonstration ===\n" << endl;
    
    for (int n = 1; n <= 3; n++) {
        cout << "Solving Tower of Hanoi with " << n << " disk(s):" << endl;
        cout << "From rod A to rod C using rod B as auxiliary\n" << endl;
        
        printTowerOfHanoi(n, 'A', 'C', 'B');
        
        int totalMoves = solution.towerOfHanoi(n, 1, 3, 2);
        cout << "\nTotal moves: " << totalMoves << endl;
        cout << string(40, '-') << endl;
    }
    
    // Performance test for larger values
    cout << "\n=== Performance Test ===\n" << endl;
    
    vector<int> largeCases = {10, 15, 20};
    for (int n : largeCases) {
        int moves = solution.towerOfHanoi(n, 1, 3, 2);
        cout << "n = " << n << " disks: " << moves << " moves" << endl;
    }
    
    cout << "\nNote: For n=20, that's over 1 million moves!" << endl;
    cout << "The exponential growth (2^n - 1) makes this problem computationally expensive for large n." << endl;
    
    return 0;
}
