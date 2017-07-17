#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0;
        int high = n - 1;
        int mid = (low + high)/2;
        while (low <= high) {
            mid = (low + high)/2;
            if (A[mid] == target)
               return mid;
            if (A[mid] >= A[low]) {
               if (A[low] <= target && target < A[mid])
                   high = mid - 1;
               else
                   low = mid + 1;
            } else {
               if (A[mid] < target && target <= A[high])
                   low = mid + 1;
               else
                   high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 7;
    Solution solu = Solution();
    cout << solu.search(A, sizeof(A)/sizeof(int), target) << endl;
}
