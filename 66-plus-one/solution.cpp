#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        int carry = 1;
        int sum = 0;
        while (--len >= 0 && carry != 0) {
            sum = digits[len] + carry;
            carry = sum / 10;
            digits[len] = sum % 10;
        }
        if (carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main() {
    Solution solu = Solution();
    vector<int> digits = {1, 2, 3};
    vector<int> res = solu.plusOne(digits);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ", ";
    }
    cout << endl;
}
