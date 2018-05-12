#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x == 1) return 1;
        double a = 0, b = 0;
        double M = 0.000001;
        a = rand() % (2 * x - 3) + 3;
        b = a = a / 2;
        do {
            a = b;
            b = a / 2 + x / ( 2 * a);
        } while (abs(b-a) > M);
        return b;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.sqrt(2) << endl;
}
