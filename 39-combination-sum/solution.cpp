#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<vector<int> > tmp;
        vector<int> subcand;


        if (candidates.size() == 0)
            return res;

        sort(candidates.begin(), candidates.end());
        int head = candidates[0];
        int times = target / head;

        if (candidates.size() == 1) {
            if (target % candidates.front() == 0) {
                for (int i = 1; i <= times; i++)
                    subcand.push_back(candidates.front());
                res.push_back(subcand);
                return res;
            }
            return res;
        }

        int sum = 0;
        for (times = 0; times <= target/head; times++) {
            if (0 == (target - sum)) {
                 subcand.clear();
                 for(int j = 1; j <= times; j++)
                     subcand.insert(subcand.begin(), head);
                 res.push_back(subcand);
            } else {
                 subcand.assign(candidates.begin() + 1, candidates.end());
                 tmp = combinationSum(subcand, target - sum);
                 for (int i = 0; i < tmp.size(); i++) {
                     for(int j = 1; j <= times; j++)
                         tmp[i].insert(tmp[i].begin(), head);
                     res.push_back(tmp[i]);
                 }
            }
            sum = sum + head;
        }
        return res;
    }
};

int main() {
    int A[] = {2, 3, 6, 7};
    vector<int> candidates(A, A+sizeof(A)/sizeof(int));
    int target = 7;
    Solution solu = Solution();
    vector<vector<int> > res = solu.combinationSum(candidates, target);
    for (size_t i = 0; i < res.size(); i++) {
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
}
