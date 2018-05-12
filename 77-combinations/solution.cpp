#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<vector<int> > tmp;
        if (k == 0)
            return res;
        if (k == n) {
            vector<int> one;
            for (int i = 1; i <= n; i++)
                one.push_back(i);
            res.push_back(one);
            return res;
        }
        res = combine(n - 1, k);
        tmp = combine(n - 1, k - 1);
        if (tmp.size() == 0) tmp.resize(1);
        for (int i = 0; i < tmp.size(); i++) {
            tmp[i].push_back(n);
            res.push_back(tmp[i]);
        }
        return res;
    }
};

int main() {
    Solution solu = Solution();
    vector<vector<int> res = solu.combine(4, 2);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
}
