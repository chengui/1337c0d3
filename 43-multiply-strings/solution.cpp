#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        vector<int> num, tmp;
        int n1 = num1.length(), n2 = num2.length();
        int mul = 0, carry = 0, plus = 0, a = 0, b = 0;

        if (n1 == 1 && num1[0] == '0' || n2 == 1 && num2[0] == '0')
            return string("0");

        for (int i = n1 - 1, shift = 0; i >= 0; i--, shift++) {
            tmp.clear();
            for (int j = 0; j < shift; j++)
                tmp.push_back(0);
            a = num1[i] - '0';
            carry = 0;
            for (int j = n2 - 1; j >= 0; j--) {
                b = num2[j] - '0';
                mul = a * b + carry;
                carry = mul / 10;
                mul = mul % 10;
                tmp.push_back(mul);
            }
            if (carry)
                tmp.push_back(carry);

            num.resize(tmp.size(), 0);
            carry = 0;
            for (int j = 0; j < tmp.size(); j++) {
                plus = num[j] + tmp[j] + carry;
                carry = plus / 10;
                plus = plus % 10;
                num[j] = plus;
            }
            if (carry)
                num.push_back(carry);
        }
        for (int i = num.size() - 1; i >= 0; i--)
            res += num[i] + '0';
        return res;
    }
};

int main() {
    string num1 = "123", num2 = "234";
    Solution solu = Solution();
    cout << solu.multiply(num1, num2) << endl;
}
