#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int sudoku[9][9] = {0};
        int i = 0;
        int j = 0;
        int trace[1024] = {0};
        int ptr_trace = 0;
        int backtrace = 0;

        for (i = 0; i < board.size(); i++)
            for (j = 0; j < board[i].size(); j++)
                if (board[i][j] == '.')
                    sudoku[i][j] = 0;
                else
                    sudoku[i][j] = board[i][j] - '0';

        for (i = 0; i < 9; ) {
            for (j = 0; j < 9; ) {

                if (board[i][j] != '.') {
                    j++;
                    continue;
                }

                int begin = 1;
                int k = 1;

                if (sudoku[i][j] != 0) {
                    begin = sudoku[i][j] + 1;
                }
                for (k = begin; k <= 9; k++) {
                    int dup = 0;
                    for (int row = 0; row < 9; row++) {
                        if (sudoku[i][row] == k || sudoku[row][j] == k) {
                            dup = 1;
                            break;
                        }
                    }
                    if (dup)
                        continue;

                    int ii = 0;
                    int jj = 0;
                    int idiv = i / 3;
                    int jdiv = j / 3;
                    for (ii = 3 * idiv; ii <= 3 * idiv + 2; ii++)
                        for (jj = 3 * jdiv; jj <= 3 * jdiv + 2; jj++)
                            if (sudoku[ii][jj] == k) {
                                dup = 1;
                                break;
                            }

                    if (!dup)
                        break;
                }

                if (k > 9) {
                    if (ptr_trace > 0) {
                        sudoku[i][j] = 0;
                        ptr_trace--;
                        i = trace[ptr_trace] / 10;
                        j = trace[ptr_trace] % 10;
                        trace[ptr_trace] = 0;
                    }
                } else {
                    sudoku[i][j] = k;
                    trace[ptr_trace] = i * 10 + j;
                    ptr_trace++;
                    j++;
                }

            }
            if (j == 9) i++;
        }

        for (i = 0; i < board.size(); i++)
            for (j = 0; j < board[i].size(); j++)
                if (board[i][j] == '.')
                    board[i][j] = sudoku[i][j] + '0';

    }
};

int main() {
    char A[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    vector<vector<char> > board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = A[i][j];
        }
    }

    Solution solu = Solution();
    solu.solveSudoku(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
