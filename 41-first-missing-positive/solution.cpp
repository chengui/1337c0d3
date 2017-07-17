#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int idx = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] <= 0)
                continue;
            if (A[i] > n)
                continue;
            idx = A[i]- 1;
            tmp = A[idx];
            A[i] = tmp;
            A[idx] = (idx+1);
            if (tmp != A[idx])
                i--;
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != (i+1))
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
