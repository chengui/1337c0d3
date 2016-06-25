#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int y = 0;

        while (x != 0) {
            y = 10 * y + x % 10;
            x = x / 10;
        }

        return y;
    }
};

int main() {
    int x = 123;
    Solution solu = Solution();
    cout << solu.reverse(x) << endl;
}
