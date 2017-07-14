#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return string("");
        if (strs.size() == 1)
            return strs[0];

        int mid = strs.size() / 2;
        vector<string> left;
        left.assign(strs.begin(), strs.begin() + mid);
        string s1 = longestCommonPrefix(left);
        vector<string> right;
        right.assign(strs.begin() + mid, strs.end());
        string s2 = longestCommonPrefix(right);
        int i = 0;
        for (; i < s1.length() && i < s2.length() && s1[i] == s2[i]; i++);
        return s1.substr(0, i);

    }
};

int main() {
    const char* args[] = {
        "abcdefghi",
        "abcefghi",
        "abcfghi",
        "abcghi"
    };
    vector<string> strs(args, args+4);
    Solution solu = Solution();
    cout << solu.longestCommonPrefix(strs) << endl;
}
