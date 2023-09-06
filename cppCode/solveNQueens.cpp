#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chess(n, string(n, '.'));
        backtrack(n, 0, chess);
        return result;
    }
    void backtrack(int n, int row, vector<string> &chess)
    {
        if(chess.size() == row)
        {
            result.push_back(chess);
            return;
        }
        for(int col = 0; col < n; ++ col)
        {
            if(isValidMatrix(row, col, chess))
            {
                chess[row][col] = 'Q';
                backtrack(n, row + 1, chess);
                chess[row][col] = '.';
            }
        }
        return;
    }
    bool isValidMatrix(int row, int col, vector<string> &chess)
    {
        for(int i = 0; i < row; ++ i)
        {
            if(chess[i][col] == 'Q')
            {
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >=0; -- j, -- i)
        {
            if(chess[i][j] == 'Q')
            {
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; ++ j, -- i)
        {
            if(chess[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<string>> result;
};

int main()
{
    return 0;
}