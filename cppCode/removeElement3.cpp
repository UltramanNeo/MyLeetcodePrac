#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // int slowPointer = 0;
        // int size = nums.size();
        // for(int quickPointer = 0; quickPointer < size; ++ quickPointer) {
        //     if (val != nums.at(quickPointer))
        //     {
        //         nums.at(slowPointer) = nums.at(quickPointer);
        //         ++ slowPointer;
        //     }
            
        // }
        // return slowPointer;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            while(left <= right && nums[left] != val)
            {
                ++ left;
            }
            while(left <= right && nums[right] == val)
            {
                -- right;
            }
            if(left < right)
            {
                nums[left ++] = nums[right --];
            }
        }
        return left;
        
    }

};
int main()
{
    // vector<int> a{1, 2,2,2,2,2,2, 4, 5, 6};
    vector<int> a{2};
    cout << Solution().removeElement(a, 3) << ends;
    return 0;
}