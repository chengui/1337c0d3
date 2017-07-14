#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int i = 0, j = 0, k = 0, twosum = 0;
        vector<vector<int> > res;
        vector<int> triplet;
        if (num.size() == 0)
            return res;
        sort(num.begin(), num.end());
        for (i = 0; i < num.size(); i++) {
            j = i+1; k = num.size()-1;
            while (j < k) {

                twosum = (num[j] + num[k]) * (-1);
                if (twosum == num[i]) {
                    triplet.push_back(num[i]);
                    triplet.push_back(num[j]);
                    triplet.push_back(num[k]);
                    res.push_back(triplet);
                    triplet.clear();
                    while (num[j] == num[j+1]) j++;
                    while (num[k] == num[k-1]) k--;
                    j++;
                    k--;
                } else if (twosum > num[i])
                    j++;
                else
                    k--;
            }
            while (num[i] == num[i+1]) i++;
        }
        return res;
    }
};

int main() {
    int A[] = {-1, 0, 1, 2, -1, -4};
    vector<int> num;
    num.assign(A, A+sizeof(A)/sizeof(int));
    Solution solu = Solution();
    vector<vector<int> > res = solu.threeSum(num);
    for(vector<vector<int> >::iterator it = res.begin(); it != res.end(); it++) {
        for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++) {
            cout << *jt << ", ";
        }
        cout << endl;
    }
}
