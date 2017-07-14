#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string expandArround(string s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
    string longestPalindrome(string s) {
        if (s.length() == 0)
            return s;
        string longest;
        for (int i = 0; i < s.length(); i++) {
            string p1 = expandArround(s, i, i);
            if (p1.length() > longest.length())
                longest = p1;
            string p2 = expandArround(s, i, i+1);
            if (p2.length() > longest.length())
                longest = p2;
        }
        return longest;
    }
};

int main() {
    string s = "babad";
    Solution solu = Solution();
    cout << solu.longestPalindrome(s) << endl;
}
