#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0)
            return 1;
        double res = 1.0;
        int flag = 1;
        if (x < 0) {
            x = -x;
            flag = -1;
        }
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        if (n % 2 == 0)
            flag = 1;
        if (x == 1.0) return flag * res;
        for (int i = 1; i <= n; i++) {
            if (res <= numeric_limits<double>::min() || res >= numeric_limits<double>::max())
                break;
            res *= x;
        }
        return flag * res;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.pow(3.0, 3) << endl;
}
