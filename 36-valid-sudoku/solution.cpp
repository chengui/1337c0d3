#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.')
                    continue;

                for (int k = 0; k < 9; k++)
                    if (board[i][k] == board[i][j] && k != j)
                        return false;
                for (int k = 0; k < 9; k++)
                    if (board[k][j] == board[i][j] && k != i)
                        return false;

                int iblock = i / 3;
                int jblock = j / 3;
                for (int ii = iblock * 3; ii <= iblock * 3 + 2; ii++)
                    for (int jj = jblock * 3; jj <= jblock * 3 + 2; jj++)
                        if (board[i][j] == board[ii][jj] && i != ii && j != jj)
                            return false;
            }

        return true;
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
    cout << solu.isValidSudoku(board) << endl;
}
