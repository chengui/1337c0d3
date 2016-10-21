#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> cnt;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (cnt.count(nums[i]))
                return true;
            else
                cnt[nums[i]] = 1;
        }
        return false;
    }
};

int main()
{
    int tmp[] = {1, 2, 3, 4, 5, 0};
    vector<int> nums(tmp, tmp + sizeof(tmp)/sizeof(int));
    Solution s = Solution();
    cout << s.containsDuplicate(nums) << endl;
}
