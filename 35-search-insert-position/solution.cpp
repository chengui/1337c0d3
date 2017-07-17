#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i = 0;
        for (i = 0; i < n; i++)
            if (target <= A[i])
                break;

        return i;
    }
};

int main() {
    int A[] = {1, 3, 5, 6};
    int target = 5;
    Solution solu = Solution();
    cout << solu.searchInsert(A, sizeof(A)/sizeof(int), target) << endl;
}
