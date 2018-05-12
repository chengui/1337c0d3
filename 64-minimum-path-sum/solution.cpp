#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 1 || n < 1)
            return 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                    grid[i][j] += grid[i][j - 1];
                else if (j == 0)
                    grid[i][j] += grid[i - 1][j];
                else if (grid[i - 1][j] < grid[i][j - 1])
                    grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += grid[i][j - 1];
            }
        return  grid[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid(3, vector<int>(3, 1));
    grid[0][1] = 3, grid[1][1] = 5, grid[2][0] = 4, grid[2][1] = 2;
    Solution solu = Solution();
    cout << solu.minPathSum(grid) << endl;
}
