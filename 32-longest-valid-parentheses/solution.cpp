#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0)
            return 0;

        stack<int> valid;
        int *length = new int[s.length()];
        int longest= 0, len = 0, ch = 0;
        for (int i = 0; i < s.length(); i++) {
            if (valid.empty()) {
                valid.push(i);
                length[i] = 0;
                len = 0;
                continue;
            }
            ch = valid.top();
            if (s[ch] == '(' && s[i] == ')') {
                valid.pop();
                len += 2;
                if (ch > 0 && length[ch-1] > 0)
                    len += length[ch-1];
                length[i] = len;
                if (length[i] > longest)
                    longest = length[i];
            } else {
                valid.push(i);
                length[i] = 0;
                len = 0;
            }
        }
        return longest;
    }
};

int main() {
    string s = ")()())";
    Solution solu = Solution();
    cout << solu.longestValidParentheses(s) << endl;
}
