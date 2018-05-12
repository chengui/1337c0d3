#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int count = 0;
        int size = S.size();
        int total = 1 << size;
        vector<vector<int> > result;

        sort(S.begin(), S.end(), less<int>());
        while (count < total) {
            vector<int> onesubset;
            for (int i = 0; i < size; i++) {
                if (1 & (count >> i))
                    onesubset.push_back(S[i]);
            }
            result.push_back(onesubset);
            count++;
        }
        return result;
    }
};

int main() {
    vector<int> S = {1, 2, 3};
    Solution solu = Solution();
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S[i].size(); j++) {
            cout << S[i][j] << ", ";
        }
        cout << endl;
    }
}
