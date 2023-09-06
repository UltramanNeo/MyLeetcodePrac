#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // 2 damen
    vector<int> weight;
    vector<int> value;

    int wSize = weight.size();
    int vSize = value.size();
    vector<vector<int>> dp(vSize, vector<int>(wSize + 1, 0));
    for(int i = 0; i < wSize; ++ i)
    {
        dp[0][i] = value[0];
    }

    for(int i = 0; i < vSize; ++ i)
    {
        for(int j = 0; j < wSize; ++ j)
        {
            if(j < weight[i])
            {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[vSize - 1][wSize];


    // 1 damon

}