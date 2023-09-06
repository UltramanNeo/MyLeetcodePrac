#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
    void backtrack(int n, int k, int begingIndex)
    {
        if(path.size() == k)
        {
            result.push_back(path);
        }

        for(int i = begingIndex; i <= n; ++ i)
        {
            path.push_back(i);
            backtrack(n, k, begingIndex);
            path.pop_back();
        }
        return;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
};

int main()
{
    return 0;
}