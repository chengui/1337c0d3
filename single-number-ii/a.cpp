#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int pow[32] = {0};  //count how many 1 in the ith bit (mod 3)
        int single = 0;  //value of the single one

        //count all integers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++)  //count each bitset
                if ((A[i]>>j) & 1)  //count if 1 is set
                    pow[j] = (pow[j] + 1) % 3;  //count by mod 3 
        }

        //recover that single one by left bits
        for (int j = 0; j < 32; j++)
            single |= pow[j]<<j;

        return single;
    }
};

int main() {
    int A[] = {1, 1, 1, 2, 2, 2, 3};
    int n = sizeof(A)/sizeof(int);
    Solution solu = Solution();
    cout << solu.singleNumber(A, n) << endl;
}
