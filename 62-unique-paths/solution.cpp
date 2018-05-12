#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int> > triangle;
       int sum = 0;
       triangle.resize(m);
       for (int i = 0; i < m; i++) {
           triangle[i].resize(n);
           for (int j = 0; j < n; j++) {
               if (j == 0 || i == 0)
                   sum = 1;
               else
                   sum = triangle[i - 1][j] + triangle[i][j - 1];
               triangle[i][j] = sum;
           }
       }
       return triangle[m - 1][n - 1];
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.uniquePaths(3, 2) << endl;
}
