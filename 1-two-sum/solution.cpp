#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    static bool less_first(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    };

    vector<int> twoSum(vector<int> &numbers, int target) {

        int i = 0;
        int j = numbers.size() - 1;
        vector<int> res;
        vector<pair<int, int> > num;
        for (int k = 0; k < numbers.size(); k++)
            num.push_back(make_pair(numbers[k], k+1));
        sort(num.begin(), num.end(), less_first);
        while (i < j) {
            int sum = num[i].first + num[j].first;
            if (target == sum) {
                res.push_back(num[i].second);
                res.push_back(num[j].second);
                return res;
            }
            if (target < sum)
                j--;
            else
                i++;
        }
        return res;
    }
};

int main() {
    int A[] = {7, 2, 11, 2};
    vector<int> num;
    num.assign(A, A+sizeof(A)/sizeof(int));
    Solution solu = Solution();
    vector<int> res = solu.twoSum(num, 4);
    cout << res[0] << "," << res[1] << endl;
}
