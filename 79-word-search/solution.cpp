#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    struct Triple {
        int r;
        int c;
        int p;
        Triple(int r, int c, int p): r(r), c(c), p(p) {}
    };

    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size();
        if (row == 0 || word.size() == 0) return false;
        int col = board[0].size();
        vector<vector<bool> > visit(row, vector<bool>(col, 0));
        stack<Triple> stk;
        Triple cur(0, 0, 0);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                if (word[0] != board[i][j])
                    continue;
                stk.push(Triple(i, j, 0));
                while (!stk.empty()) {
                    cur = stk.top();
                    if (!visit[cur.r][cur.c]) {
                        if (board[cur.r][cur.c] == word[cur.p]) {
                            if (cur.p == word.size()-1)
                                return true;

                            visit[cur.r][cur.c] = true;
                            if (cur.r-1 >= 0 && !visit[cur.r-1][cur.c])
                                stk.push(Triple(cur.r-1, cur.c, cur.p+1));
                            if (cur.r+1 < row && !visit[cur.r+1][cur.c])
                                stk.push(Triple(cur.r+1, cur.c, cur.p+1));
                            if (cur.c-1 >= 0 && !visit[cur.r][cur.c-1])
                                stk.push(Triple(cur.r, cur.c-1, cur.p+1));
                            if (cur.c+1 < col && !visit[cur.r][cur.c+1])
                                stk.push(Triple(cur.r, cur.c+1, cur.p+1));
                        } else {
                            stk.pop();
                        }

                    } else {
                        stk.pop();
                        visit[cur.r][cur.c] = false;
                    }
                }
            }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}};
    string word = "SEE";
    Solution solu= Solution();
    cout << solu.exist(board, word) << endl;
}

