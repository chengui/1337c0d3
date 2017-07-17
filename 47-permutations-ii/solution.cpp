#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        vector<vector<int> > tmp;
        int swap = 0, last = 0;
        if (num.size() == 0)
            return result;
        if (num.size() == 1) {
            result.push_back(num);
            return result;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            if (i != last && num[i] == num[last])
                continue;
            if (num[i] != num[last])
                last = i;
            //swap 0, i
            swap = num[0];
            num[0] = num[i];
            num[i] = swap;
            vector<int> v(num.begin() + 1, num.end());
            tmp = permuteUnique(v);
            for (int j = 0; j < tmp.size(); j++) {
                tmp[j].push_back(num[0]);
                result.push_back(tmp[j]);
            }
            //swap 0, i
            swap = num[0];
            num[0] = num[i];
            num[i] = swap;
        }
        return result;
    }
};

int main() {
    int A[] = {1, 1, 2};
    vector<int> num(A, A + sizeof(A)/sizeof(int));
    Solution solu = Solution();
    vector<vector<int> > res = solu.permuteUnique(num);
    for (size_t i = 0; i < res.size(); i++) {
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
}
