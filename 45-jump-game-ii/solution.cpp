#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int farest = 0, last = 0;
        vector<int> steps;
        for (int i = 0; i < (n-1); i++) {
            if (i <= farest && (i+A[i]) > farest) {
                farest = i + A[i];
                int j = 0;
                for (j = 0; j < steps.size(); j++) {
                    last = steps[j];
                    if (i <= (last + A[last]))
                        break;
                }
                if (steps.empty())
                    steps.push_back(i);
                else {
                    steps.erase(steps.begin() + j+1, steps.end());
                    steps.push_back(i);
                }
            }
            if (farest >= (n-1))
                return steps.size();
        }
        return 0;
    }
};

int main() {
    int A[] = {2, 3, 1, 1, 4};
    Solution solu = Solution();
    cout << solu.jump(A, sizeof(A)/sizeof(int)) << endl;
}
