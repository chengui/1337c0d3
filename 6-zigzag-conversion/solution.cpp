#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        vector<string> buf(nRows, string(""));
        string res;
        bool fwd = true;
        int pos = 0;
        for (int i = 0; i < s.length(); i++) {
            buf[pos] += s[i];
            if (pos == (nRows - 1))
                fwd = false;
            if (pos == 0)
                fwd = true;
            if (fwd)
                pos++;
            else
                pos--;
        }
        for (int i = 0; i < buf.size(); i++)
            res += buf[i];
        return res;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    Solution solu = Solution();
    cout << solu.convert(s, 3) << endl;
}
