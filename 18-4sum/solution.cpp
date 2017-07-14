#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int a = 0, b = 0, c = 0, d = 0;
        int len = 0;
        vector<vector<int> > result;
        vector<int> item;

        len = num.size();
        if (len < 1)
            return result;

        sort(num.begin(), num.end(), less<int>());
        for(a = 0; a <= len - 3; a++) {
            for(b = a + 1; b <= len - 2; b++) {
                int twosum = target - num[a] - num[b];
                c = b + 1;
                d = len - 1;
                while (c < d) {
                    if ((num[c] + num[d]) == twosum) {
                        item.push_back(num[a]);
                        item.push_back(num[b]);
                        item.push_back(num[c]);
                        item.push_back(num[d]);
                        result.push_back(item);
                        item.clear();
                        while(num[c] == num[c+1]) c++;
                        while(num[d] == num[d-1]) d--;
                        c++;
                        d--;
                    } else if ((num[c] + num[d]) < twosum)
                        c++;
                    else
                        d--;
                }
                while(num[b] == num[b+1]) b++;
            }
            while(num[a] == num[a+1]) a++;
        }
        return result;
    }
};

int main() {
    int A[] = {1, 0, -1, 0, -2, 2};
    vector<int> num;
    num.assign(A, A+sizeof(A)/sizeof(int));
    int target = 0;
    Solution solu = Solution();
    vector<vector<int> > res = solu.fourSum(num, target);
    for (vector<vector<int> >::iterator it = res.begin(); it != res.end(); it++) {
        for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++) {
            cout << *jt << ", ";
        }
        cout << endl;
    }
}
