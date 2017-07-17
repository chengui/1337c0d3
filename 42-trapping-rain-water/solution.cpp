#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        vector<int> water;
        int rain = 0;
        int top = 0;
        int wtop = 0;

        water.push_back(0);
        for (int i = 1; i < n; i++) {
            top = water.back();
            if (A[i] >= A[water.front()]) {
                wtop = water.back();
                while (!water.empty()) {
                    top = water.back();
                    water.pop_back();
                    rain += (A[top] - A[wtop]) * (i - 1 - top);
                    wtop = top;
                }
                water.clear();
                water.push_back(i);
            } else if (A[i] <= A[top]) {
                water.push_back(i);
            } else {
                wtop = water.back();
                while (!water.empty()) {
                    top = water.back();
                    if (A[top] >= A[i]) {
                        rain += (A[i] - A[wtop]) * (i - 1 - top);
                        break;
                    }
                    water.pop_back();
                    rain += (A[top] - A[wtop]) * (i - 1 - top);
                    wtop = top;
                }

                water.push_back(i);
            }
        }

        return rain;

    }
};

int main() {
    int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution solu = Solution();
    cout << solu.trap(A, sizeof(A)/sizeof(int)) << endl;
}
