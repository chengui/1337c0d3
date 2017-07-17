#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
            string res;
            string tmp;
            if (n == 0) return res;
            res = "1";
            while (n > 1) {
                int size = res.length();
                int idx = 0;
                tmp.clear();
                while (idx < size){
                    char c = res[idx];
                    int end = res.find_first_not_of(&c, idx);
                    if (end == string::npos){
                        end = size;
                    }
                    tmp += std::to_string(end - idx);
                    tmp += res[idx];
                    idx = end;
                }
                res.clear();
                res.assign(tmp);
                n--;
//                cout <<res<<endl;
            }
            return res;
    }
};

int main() {
    Solution solu = Solution();
    cout << solu.countAndSay(4) << endl;
}
