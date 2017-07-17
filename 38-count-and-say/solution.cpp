#include <iostream>
#include <string>
#include <sstream>

using namespace std;

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        return "1";
        if (n == 2)
        return "11";
        int cnt = 1;
        int i = 0;
        stringstream rs;
        string st = countAndSay(n - 1);
        for(i = 1; i < st.length(); i++) {
        if (st[i] == st[i - 1]) {
            cnt++;
        } else {
            rs << cnt;
            rs << st[i-1];
            cnt = 1;
        }
        }
        rs << cnt;
        rs << st[i-1];
        return rs.str();
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.countAndSay(4) << endl;
}
