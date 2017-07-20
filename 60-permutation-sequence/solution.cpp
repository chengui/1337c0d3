#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res("");
        vector<int> digits;
        int permute = 1;
        int div = 0, mod = 0;
        for (int i = 1; i < n; i++)
            permute *= i;
        for (int i = 1; i <= n; i++)
            digits.push_back(i);
        k = k - 1;
        for(int i = (n-1); i >= 1; i--)  {
            div = k / permute;
            k = k % permute;
            permute /= i;
            res.append(1, '0' + digits[div]);
            digits.erase(digits.begin() + div);
        }
        res.append(1, '0' + digits[0]);
        return res;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.getPermutation(3, 4) << endl;
}
