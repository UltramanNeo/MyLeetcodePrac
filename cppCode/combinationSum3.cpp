#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 0, 1);
        return result;
    }
    void backtrack(int k, int n, int sum, int beginIndex)
    {
        if(path.size() == k)
        {
            if(sum == n)
            {
                result.push_back(path);
            }
            return;
        }
        for(int i = beginIndex; i <= 9; ++ i)
        {
            path.push_back(i);
            sum += i;
            backtrack(k, n, sum, i + 1);
            sum -= i;
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