#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int bits[60] = {0};
        for (int i = 0; i < 60; i++)
        {
            for (int j = 0; j < 6; j++)
                if ((i>>j)&1) bits[i]++;
        }

        char buf[5] = {0};
        vector<string> ret;
        for (int i = 0; i <= num; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                if ((num - i) == bits[j])
                {
                    for (int k = 0; k < 60; k++)
                    {
                        if (i == bits[k])
                        {
                            sprintf(buf, "%d:%02d", j, k);
                            ret.push_back(string(buf));
                        }
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    int num = 1;
    Solution s = Solution();
    vector<string> ret = s.readBinaryWatch(num);
    for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
    {
        cout << *it << ", ";
    }
    cout << endl;
}
