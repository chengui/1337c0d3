#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > allboard;
        vector<string> board;
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
                board.clear();
                for (int k = 0; k < n; k++) {
                    string repr(n, '.');
                    repr[queens[k]] = 'Q';
                    board.push_back(repr);
                }
                allboard.push_back(board);
                forward = false;
            }
        } while (!queens.empty());
        return allboard;
    }
};

int main() {
    Solution solu = Solution();
    vector<vector<string> > res = solu.solveNQueens(4);
    for (vector<vector<string> >::iterator it = res.begin(); it != res.end(); it++) {
        for (vector<string>::iterator jt = it->begin(); jt != it->end(); jt++) {
            cout << *jt << endl;
        }
    }
}
