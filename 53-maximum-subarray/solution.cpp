#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) return 0;
        int max_so_far = A[0];
        int max_end_here = A[0];

        for (int i = 1; i < n; i++) {
            if (max_end_here < 0)
                max_end_here = A[i];
            else
                max_end_here += A[i];

            if (max_end_here >= max_so_far)
                max_so_far = max_end_here;
        }
        return max_so_far;
    }
};

int main() {
    int A[] = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    Solution solu = Solution();
    cout << solu.maxSubArray(A, sizeof(A)/sizeof(int)) << endl;
}
