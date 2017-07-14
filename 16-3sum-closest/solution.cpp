#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        int sum = 0;
        int tmp = 0;

        sort(num.begin(), num.end());
        sum = num[0] + num[1] + num[2];
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                tmp = num[j] + num[k];
                if (abs(num[i] + tmp - target) < abs(sum - target))
                    sum = num[i] + tmp;
                if (tmp < (target - num[i]))
                    j++;
                else
                    k--;
            }
        }

        return sum;
    }
};

int main() {
    int A[] = {-1, 2, 1, -4};
    vector<int> num;
    num.assign(A, A+sizeof(A)/sizeof(int));
    int target = 2;
    Solution solu = Solution();
    cout << solu.threeSumClosest(num, target) << endl;
}
