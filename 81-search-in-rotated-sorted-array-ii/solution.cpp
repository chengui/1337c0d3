#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int i = 0;
        if (n <= 0)
            return false;
        if (n == 1)
            return (target == A[0]);
        for (i = 1; i < n; i++)
            if (A[i-1] > A[i])
                break;
        return binary_search(A, A+i, target) || binary_search(A+i, A+n, target);
    }
};

int main() {
    int A[] = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    Solution solu = Solution();
    cout << solu.search(A, sizeof(A)/sizeof(int), target) << endl;
}
