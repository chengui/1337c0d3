#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define SSTR(x) static_cast<std::ostringstream &>(std::ostringstream() << std::dec << x).str()

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t i = 0, j = nums.size();
        while (i < j)
        {
            if (nums[i] == 0)
            {
                nums.push_back(nums[i]);
                nums.erase(nums.begin() + i);
                j--;
            }
            else
            {
                i++;
            }
        }
    }
};

string str(vector<int>& nums)
{
    string r = "[";
    for (size_t i = 0; i < nums.size(); i++)
    {
        r += SSTR(nums[i]) + ", ";
    }
    r += "]";
    return r;
}

int main()
{
    // int tmp[] = {0};
    // int tmp[] = {1, 0, 2, 0, 10};
    int tmp[] = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    vector<int> nums(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));
    Solution s = Solution();
    cout << str(nums) << endl;
    s.moveZeroes(nums);
    cout << str(nums) << endl;
}
