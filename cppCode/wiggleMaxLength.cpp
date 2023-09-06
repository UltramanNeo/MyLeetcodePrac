#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 1;
        int cur = 0;
        int pre = 0;
        int size = nums.size();
        for(int i = 0; i < size - 1; ++ i)
        {
            cur = nums[i + 1] - nums[i];
            if((pre >= 0 && cur < 0) || (pre <= 0 && cur > 0))
            {
                ++ result;
                pre = cur;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}