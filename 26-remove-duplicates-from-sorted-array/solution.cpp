#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;

        int begin = 0;
        int pointer = 0;
        while (pointer < n) {
            int pp = 0, ppp = 0;
            for (pp = pointer + 1; pp < n && A[pp] == A[pointer]; pp++);
            ppp = pp;
            for (int j = pointer; j >= begin; j--, pp--)
                A[pp - 1] = A[j];
            begin = pp;
            pointer = ppp;

        }

        for (int i = begin; i < n; i++)
            A[i - begin] = A[i];
        return (n - begin);
    }
};

int main() {
    int A[] = {1, 1, 2};
    Solution solu = Solution();
    cout << solu.removeDuplicates(A, sizeof(A)/sizeof(int)) << endl;
}
