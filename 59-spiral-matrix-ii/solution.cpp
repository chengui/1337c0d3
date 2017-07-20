#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        result.resize(n);
        for (int i = 0; i < result.size(); i++)
            result[i].resize(n);

        int end = n - 1;
        int num = 1;
        int lp = 0;
        while (lp < n/2) {

            for (int i = lp; i < end; i++, num++)
                result[lp][i] = num;
            for (int i = lp; i < end; i++, num++)
                result[i][end] = num;
            for (int i = end; i > lp; i--, num++)
                result[end][i] = num;
            for (int i = end; i > lp; i--, num++)
                result[i][lp] = num;
            end--;
            lp++;
        }
        if (n%2 == 1) {
            result[lp][lp] = num;
        }

        return result;
    }
};

int main() {
    Solution solu = Solution();
    vector<vector<int> > res = solu.generateMatrix(3);
    for (size_t i = 0; i < res.size(); i++) {
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
}
