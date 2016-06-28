#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int *C = new int[m+n];
        int i = 0, j = 0;
        for (i = 0; i < m; i++, j++)
            C[j] = A[i];
        for (i = 0; i < n; i++, j++)
            C[j] = B[i];
        sort(C, C+(m+n));
        if ((m+n) % 2)
            return C[(m+n)/2];
        else
            return (C[(m+n)/2-1]+C[(m+n)/2])/2.0;        
    }
};

int main()
{
    //int A[2] = {1, 2}, B[1] = {2};
    int A[2] = {1, 2}, B[2] = {3, 4};
    Solution s = Solution();
    printf("%f\n", s.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)));
}
