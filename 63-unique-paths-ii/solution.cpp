#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int mlen = obstacleGrid.size();
        int nlen = obstacleGrid[0].size();
        int herizon = 1, vertical = 1;
        for(int i = 0; i < obstacleGrid.size(); i++) {
            for(int j = 0; j < obstacleGrid[i].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    if (i == 0)
                        herizon = 0;
                    if (j == 0)
                        vertical = 0;
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if (i == 0 || j == 0) {
                    if (i == 0)
                        obstacleGrid[i][j] = herizon;
                    if (j == 0)
                        obstacleGrid[i][j] = vertical;
                } else
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
            }
        }
        return obstacleGrid[mlen - 1][nlen - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
    obstacleGrid[1][1] = 1;
    Solution solu = Solution();
    cout << solu.uniquePathsWithObstacles(obstacleGrid) << endl;
}
