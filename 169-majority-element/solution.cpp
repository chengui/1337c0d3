#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        size_t n = nums.size();
        map<int, size_t> cnt;
        for (size_t i = 0; i < n; i++)
        {
            if (!cnt.count(nums[i]))
                cnt[nums[i]] = 1;
            else
                cnt[nums[i]]++;

            if (cnt[nums[i]] > n / 2)
                return nums[i];
        }
        return 0;
    }
};

int main()
{
    // int tmp[] = {1, 2, 3, 1, 3, 1};
    int tmp[] = {6, 5, 5};
    vector<int> nums(tmp, tmp + sizeof(tmp)/sizeof(int));
    Solution s = Solution();
    cout << s.majorityElement(nums) << endl;
}
