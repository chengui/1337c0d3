#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> dict;
        stack<char> paren;
        char cur;

        dict['('] = ')';
        dict['{'] = '}';
        dict['['] = ']';

        for (int i = 0; i < s.length(); i++) {
            if (dict.find(s[i]) != dict.end())
                paren.push(s[i]);
            else if (!paren.empty()){
                cur = paren.top();
                paren.pop();
                if (dict[cur] != s[i])
                    return false;
            } else
                return false;
        }
        return paren.empty();
    }
};

int main() {
    string s = "()[]{}";
    Solution solu = Solution();
    cout << solu.isValid(s) << endl;
}
