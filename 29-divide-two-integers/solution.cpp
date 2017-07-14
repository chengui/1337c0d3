#include <iostream>

using namespace std;

class Solution {
    public:
    int divide(int dividend, int divisor) {
            return dividend/divisor;
        }
};

int main() {
    Solution solu = Solution();
    cout << solu.divide(4, 2) << endl;
}
