#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int size = nums.size();
        if(accumulate(nums.cbegin(), nums.cend(), 0) % size == 1)
        {
            return false;
        }
        int target = accumulate(nums.cbegin(), nums.cend(), 0) / 2;
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < size; ++ i)
        {
            for(int j = target; j >= nums[i]; -- j)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
            cout << endl;
        }
        // cout << dp[target] << ' ' << target << endl;
        if(dp[target] == target)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<int> a{23,13,11,7,6,5,5};
    Solution().canPartition(a);
    return 0;
}