#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int i = 0, j = 0;
        int tmp = 0;
        int k = n - 1;
        for (i = 0; i < n/2; i++) {
            for (j = i; j < k - i; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[k - j][i];
                matrix[k - j][i] = matrix[k - i][k - j];
                matrix[k - i][k - j] = matrix[j][k - i];
                matrix[j][k - i] = tmp;
            }
        }
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
    solu.rotate(matrix);

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
}
