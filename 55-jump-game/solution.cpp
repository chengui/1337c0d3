#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        set<int> farest;
        set<int>::iterator iter;
        farest.insert(0);
        for (int i = 0; i < n; i++) {
            for (iter = farest.begin(); iter != farest.end(); iter++) {
                if (*iter >= (n - 1))
                    return true;

                if (i <= *iter)
                    farest.insert(i + A[i]);
            }
        }

        return false;
    }
};

int main() {
    int A[] = {2, 3, 1, 1, 4};
    Solution solu = Solution();
    cout << solu.canJump(A, sizeof(A)/sizeof(int)) << endl;
}
