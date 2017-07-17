#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        if (len <= 1)
            return;
        int i = 0, j = 0;
        for (i = (len-2); i >= 0; i--) {
            if (num[i] < num[i+1])
                break;
        }
        if (i < 0) {
            reverse(num.begin(), num.end());
            return;
        }
        for (j = (len-1); j > i; j--) {
            if (num[j] > num[i])
                break;
        }
        //swap
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
        return;
    }
};

int main() {
    int A[] = {1, 2, 3};
    vector<int> num(A, A+sizeof(A)/sizeof(int));
    Solution solu = Solution();
    solu.nextPermutation(num);
    for (vector<int>::iterator it = num.begin(); it != num.end(); it++) {
        cout << *it << ",";
    }
    cout << endl;
}
