#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int size = (int) nums.size();
        if (size <= 1)
            return 0;

        long diff = 0;
        int min = nums[0];
        for (int i = 0; i < size; i++)
        {
            if (min > nums[i])
                min = nums[i];
        }
        for (int i = 0; i < size; i++)
        {
            diff += nums[i] - min;
        }

        return diff;
    }
};

int main()
{
    // int tmp[] = {1,1,2147483647};
    // int tmp[] = {-100, 0, 100};
    int tmp[] = {1,2,3};
    vector<int> nums(tmp, tmp+sizeof(tmp)/sizeof(int));
    Solution s = Solution();
    cout << s.minMoves(nums) << endl;
}

