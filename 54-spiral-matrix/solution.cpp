#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.size() == 0)
            return result;
        int xst = 0, xed = matrix[0].size() - 1;
        int yst = 0, yed = matrix.size() - 1;
        while (xst < xed && yst < yed) {
            for (int k = xst; k < xed; k++)
                result.push_back(matrix[yst][k]);
            for (int k = yst; k < yed; k++)
                result.push_back(matrix[k][xed]);
            for (int k = xed; k > xst; k--)
                result.push_back(matrix[yed][k]);
            for (int k = yed; k > yst; k--)
                result.push_back(matrix[k][xst]);
            xst++; yst++;
            xed--; yed--;
        }
        if (xst == yst && yst == yed && xst == xed) {
            result.push_back(matrix[xst][yst]);
        } else if (xst == xed) {
            for (int k = yst; k <= yed; k++)
                result.push_back(matrix[k][xst]);
        } else if (yst == yed) {
            for (int k = xst; k <= xed; k++)
                result.push_back(matrix[yst][k]);
        }
        return result;
    }
};

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    vector<vector<int> > matrix(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = A[i][j];
        }
    }

    Solution solu = Solution();
    vector<int> res = solu.spiralOrder(matrix);
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << ", ";
    }
    cout << endl;
}
