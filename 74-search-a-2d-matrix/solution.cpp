#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int low = 0, high = matrix.size() - 1;
        int mid = 0, len = 0;
        if (matrix.size() <= 0) return false;
        while (low <= high) {
            mid = (low + high) / 2;
            len = matrix[mid].size();
            if (matrix[mid][0] <= target && target <= matrix[mid][len - 1])
                break;
            if (matrix[mid][0] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return binary_search(matrix[mid].begin(), matrix[mid].end(), target);

    }
};

int main() {
    vector<vector<int>> matrix = {{2, 1, 3}, {5, 4, 6}};
    Solution solu = Solution();
    cout << solu.searchMatrix(matrix, 4) << endl;
}
