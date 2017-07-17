#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> index, value;
        int sum = 0, idx = 0;
        bool forward = true;
        sort(num.begin(), num.end());
        do {
            if (forward) {
                if (index.empty())
                    idx = 0;
                else
                    idx = index.back() + 1;
            } else {
                idx = index.back() + 1;
                while (num[idx] == value.back())
                    idx++;
            }
            if (idx >= num.size()) {
                index.pop_back();
                value.pop_back();
                forward = false;
                continue;
            }
            if (forward) {
                index.push_back(idx);
                value.push_back(num[idx]);
            } else {
                index.back() = idx;
                value.back() = num[idx];
            }
            sum = 0;
            for (int i = 0; i < value.size(); i++)
                sum += value[i];
            forward = true;
            if (idx >= num.size() || sum >= target) {
                 if (sum == target)
                     res.push_back(value);
                 index.pop_back();
                 value.pop_back();
                 forward = false;
            }
        } while (!value.empty());
        return res;
    }
};

int main() {
    int A[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> num(A, A + sizeof(A)/sizeof(int));
    int target = 8;
    Solution solu = Solution();
    vector<vector<int> > res = solu.combinationSum2(num, target);
    for (size_t i = 0; i < res.size(); i++) {
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
}
