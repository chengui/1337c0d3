#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0, cnt = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[maj])
                cnt++;
            else
                cnt--;

            if (cnt == 0)
            {
                maj = i;
                cnt = 1;
            }
        }
        return nums[maj];
    }
};

int main()
{
    // int tmp[] = {1, 2, 1, 2, 1, 2, 1};
    // int tmp[] = {6, 6, 5, 5, 5};
    // int tmp[] = {3, 3, 4};
    int tmp[] = {3, 2, 3};
    vector<int> nums(tmp, tmp + sizeof(tmp)/sizeof(int));
    Solution s = Solution();
    cout << s.majorityElement(nums) << endl;
}
