#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        vector<int> row(matrix.size(), 1);
        vector<int> col(matrix[0].size(), 1);
        int zerorow = 0, zerocol = 0;

        for (int i = 0; i < row.size(); i++)
            if (matrix[i][0] == 0)
                zerocol = 1;
        for (int i = 0; i < col.size(); i++)
            if (matrix[0][i] == 0)
                zerorow = 1;

        for (int i = 0; i < row.size(); i++) {
            for (int j = 0; j < col.size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < row.size(); i++) {
            if (matrix[i][0] == 0)
                for (int j = 1; j < col.size(); j++)
                    matrix[i][j] = 0;
        }

        for (int i = 1; i < col.size(); i++) {
            if (matrix[0][i] == 0)
                for (int j = 1; j < row.size(); j++)
                    matrix[j][i] = 0;
        }

        if (zerorow)
            for (int i = 0; i < col.size(); i++)
                matrix[0][i] = 0;
        if (zerocol)
            for (int i = 0; i< row.size(); i++)
                matrix[i][0] = 0;

    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {2,3,4}};
    Solution solu = Solution();
    solu.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
}
