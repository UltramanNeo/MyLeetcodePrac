#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    class DescendQueue
    {
    public:
        DescendQueue()
        {

        }
        void pop(int value)
        {
            if(!que.empty() && que.front() == value)
            {
                que.pop_front();
            }
        }
        void push(int value)
        {
            while(!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front()
        {
            return que.front();
        }
    private:
        deque<int> que;
    };
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result(0);
        DescendQueue que;
        int i = 0;
        for(; i < k; ++ i)
        {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        int size = nums.size();
        for(i = k; i < size; ++ i)
        {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
void print(vector<int> a)
{
    auto ptr = a.begin();
    auto ptrEnd = a.end();
    for(; ptr != ptrEnd; ++ ptr)
    {
        cout << *ptr << " " << ends;
    }
    cout << endl;
    return;
}
int main()
{
    vector<int> a{1,3,-1,-3,5,3,6,7};
    print(Solution().maxSlidingWindow(a, 3));

    return 0;
}