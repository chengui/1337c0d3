#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        vector<int> tmp(n, 0);
        for (int i = 0; i < n; i++) {
            if (A[i] <= 0)
                continue;
            if (A[i] > n)
                continue;
            tmp.at(A[i]-1) = 1;
        }
        for (int i = 0; i < n; i++) {
            //cout << i<<":"<<tmp[i] <<endl;
            if (tmp[i] == 0)
                return (i+1);
        }
        return (n+1);
    }
};

int main() {
    int A[] = {3, 4, -1, 1};
    Solution solu = Solution();
    cout << solu.firstMissingPositive(A, sizeof(A)/sizeof(int)) << endl;
}
