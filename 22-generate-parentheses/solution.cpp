#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 1) {
            res.push_back(string("()"));
            return res;
        }
        vector<string> tmp;
        tmp = generateParenthesis(n - 1);
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = 0; j < tmp[i].size(); j++) {
                string tstring = tmp[i];
                tstring.insert(j, "()");
                res.push_back(tstring);
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

int main() {
    int n = 3;
    Solution solu = Solution();
    vector<string> res = solu.generateParenthesis(n);
    for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << endl;
    }
}
