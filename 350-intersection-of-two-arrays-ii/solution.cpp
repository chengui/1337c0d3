#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#if __cplusplus != 201103L
#   define to_string(x) static_cast<std::ostringstream &>(std::ostringstream() << std::dec << x).str()
#endif

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        for (vector<int>::iterator it1 = nums1.begin(); it1 != nums1.end(); it1++)
        {
            for (vector<int>::iterator it2 = nums2.begin(); it2 != nums2.end(); it2++)
            {
                if (*it1 == *it2)
                {
                    ret.push_back(*it1);
                    nums2.erase(it2);
                    break;
                }
            }
        }
        return ret;
    }
};

string str(vector<int> vec)
{
    string ret = "[";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        ret += to_string(*it) + ",";
    }
    ret += "]";
    return ret;
}

int main()
{
    int tmp1[] = {1,  2, 2, 1};
    int tmp2[] = {2, 2};
    vector<int> nums1(tmp1, tmp1 + sizeof(tmp1)/sizeof(int));
    vector<int> nums2(tmp2, tmp2 + sizeof(tmp2)/sizeof(int));
    cout << str(nums1) << endl;
    cout << str(nums2) << endl;
    Solution s = Solution();
    cout << str(s.intersect(nums1, nums2)) << endl;
}
