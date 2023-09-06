#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int size = stones.size();
        int target = accumulate(stones.cbegin(), stones.cend(), 0) / 2;
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < size; ++ i)
        {
            for(int j = target; j >= stones[i]; -- j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return accumulate(stones.cbegin(), stones.cend(), 0) - dp[target] - dp[target];
    }
};


int main()
{
    return 0;
}