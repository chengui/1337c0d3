#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int st = 0, pl = path.length();
        string res, token;
        vector<string> wpath;
        for (int i = 0; i <= pl; i++) {
            if (path[i] == '/' || i == pl) {
                if (i > st + 1)
                    token = path.substr(st+1, i-1-st);
                else
                    token = "";
                if (token == "") {
                    ;
                } else if (token == ".") {
                    ;
                } else if (token == "..") {
                    if (!wpath.empty())
                        wpath.pop_back();
                } else {
                    wpath.push_back(token);
                }
                st = i;
            }
        }
        for (int i = 0; i < wpath.size(); i++)
            res += "/" + wpath[i];
        if (wpath.empty())
            res = "/";
        return res;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.simplifyPath("/home/") << endl;
}
