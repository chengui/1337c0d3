#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> calc;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0])) {
                calc.push(atoi(tokens[i].c_str()));
            } else {
                if (!calc.empty()) {
                    a = calc.top();
                    calc.pop();
                } //else exception skipped
                if (!calc.empty()) {
                    b = calc.top();
                    calc.pop();
                } //else exception skipped
                if (tokens[i] == "+")
                    c = b + a;
                else if (tokens[i] == "-")
                    c = b - a;
                else if (tokens[i] == "*")
                    c = b * a;
                else if (tokens[i] == "/")
                    c = b / a;
                //else exception skipped
                calc.push(c);
            }
        }

        if (!calc.empty())
            return calc.top();
        else
            return 0;
    }
};

int main() {
    char *repr[] = {"2", "1", "+", "3", "*"};
    vector<string> tokens;
    tokens.assign(repr, repr + sizeof(repr)/sizeof(char*));
    Solution solu = Solution();
    cout << solu.evalRPN(tokens) << endl; 
}
