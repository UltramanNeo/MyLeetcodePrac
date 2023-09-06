#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    class Comp {
    public:
        bool operator()(const pair<int, int> &left, const pair<int, int> &right)
        {
            return left.second > right.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int size = nums.size();
        for(int i = 0; i < size; ++ i)
        {
            ++ map[nums[i ++]];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> que;
        auto cur = map.begin();
        for(; cur != map.end(); ++ cur)
        {
            que.push(*cur);
            if(que.size() > k)
            {
                que.pop();
            }
        }
        vector<int> result;
        while(!que.empty())
        {
            result.push_back(que.top().first);
            que.pop();
        }
        return result;

    }
};
int main()
{
    return 0;
}