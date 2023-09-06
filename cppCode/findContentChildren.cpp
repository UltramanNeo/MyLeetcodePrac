#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int indexS = s.size() - 1;
        int result = 0;
        for(int i = g.size() - 1; i >= 0; -- i)
        {
            if(indexS >= 0 && s[indexS] >= g[i])
            {
                -- indexS;
                ++ result;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}