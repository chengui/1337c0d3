#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> queens;
        bool forward = true;
        int count = 0;
        do {
            if (forward) {
                queens.push_back(0);
            } else {
                queens.back()++;
            }
            if (queens.back() >= n) {
                queens.pop_back();
                forward = false;
                continue;
            }
            forward = true;
            for (int i = 0; i < (queens.size() - 1); i++) {
                if (queens[i] == queens.back()) {
                    forward = false;
                    break;
                }
                if ((queens.back() - queens[i]) == (queens.size() - 1 - i)) {
                    forward = false;
                    break;
                }
                if ((queens[i] - queens.back()) == (queens.size() - 1 - i)) {
                    forward = false;
                    break;
                }
            }
            if (forward && queens.size() == n) {
                count++;
                forward = false;
            }
        } while (!queens.empty());
        return count;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.totalNQueens(8) << endl;
}
