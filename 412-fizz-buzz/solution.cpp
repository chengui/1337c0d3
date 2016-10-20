#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define SSTR(x) static_cast<std::ostringstream &>(std::ostringstream() << std::dec << x).str()
// to_string is enabled since c++11
#define to_string SSTR

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
                ret.push_back("FizzBuzz");
            else if (i % 3 == 0)
                ret.push_back("Fizz");
            else if (i % 5 == 0)
                ret.push_back("Buzz");
            else
                ret.push_back(to_string(i));
        }
        return ret;
    }
};

int main()
{
    int n = 15;
    Solution s = Solution();
    vector<string> ret = s.fizzBuzz(n);
    for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
    {
        cout << *it << endl;
    }
}
