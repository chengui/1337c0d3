#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0;
        int j = 1;
        int twice = 0;
        if (n <= 0) return 0;
        while (j < n) {
            if (A[j] != A[i]) {
                i++;
                A[i] = A[j];
                twice = 0;
            } else {
                twice++;
                if (twice < 2) {
                    i++;
                    A[i] = A[j];
                }
            }
            j++;
        }
        return (i+1);
    }
};

int main() {
    int A[] = {1, 1, 1, 2, 2, 3};
    Solution solu = Solution();
    cout << solu.removeDuplicates(A, sizeof(A)/sizeof(int)) << endl;
}
