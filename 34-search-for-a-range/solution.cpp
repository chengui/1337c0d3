#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        if (n == 0)
            return result;
        int low = 0, high = n - 1;
        int mid = 0;
        while (low < high) {
            mid = low + (high - low)/2;
            if (A[mid] >= target)
                high = mid;
            else
                low = mid + 1;
        }
        if (A[low] == target)
            result.push_back(low);
        else
            result.push_back(-1);
        low = 0; high = n - 1;
        while (low < high) {
            mid = (low + high + 1)/2;
            if (A[mid] <= target)
                low = mid;
            else
                high = mid - 1;
        }
        if (A[low] == target)
            result.push_back(low);
        else
            result.push_back(-1);
        return result;
    }
};

int main() {
    int A[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution solu = Solution();
    vector<int> res = solu.searchRange(A, sizeof(A)/sizeof(int), target);
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << ",";
    }
    cout << endl;
}
