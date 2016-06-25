#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n < 1) return 0;
        int single = A[0];
        //xor operation counteracts the same integers
        //so the left one should be the single one
        for (int i = 1; i < n; i++)
            single ^= A[i];
        return single;
    }
};

int main() {
    int A[] = {1, 2, 2, 1, 3};
    int n = sizeof(A)/sizeof(int);
    Solution solu = Solution();
    cout << solu.singleNumber(A, n) << endl;
}
