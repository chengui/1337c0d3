#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        while (i < n) {
            if (elem == A[i]) {
                A[i] = A[n-1];
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};

int main() {
    int A[] = {3, 2, 2, 3};
    int elem = 3;
    Solution solu = Solution();
    cout << solu.removeElement(A, sizeof(A)/sizeof(int), elem) << endl;
}
