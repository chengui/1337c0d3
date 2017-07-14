#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int oneheight = 0, onelenth = 0, onearea = 0, maxarea = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            onelenth = j - i;
            if (height[i] >= height[j]) {
                oneheight = height[j];
                j--;
            } else {
                oneheight = height[i];
                i++;
            }
            onearea = oneheight * onelenth;
            if (onearea > maxarea)
                maxarea = onearea;
        }
        return maxarea;
    }
};

int main() {
    int A[] = {2, 5, 8, 3};
    vector<int> height;
    height.assign(A, A+sizeof(A)/sizeof(int));
    Solution solu = Solution();
    cout << solu.maxArea(height) << endl;
}
