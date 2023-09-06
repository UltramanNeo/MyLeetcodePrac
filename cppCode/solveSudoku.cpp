#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backstrack(board);
        return;
    }
    bool backstrack(vector<vector<char>>& board)
    {   
        int size = board.size();
        for(int i = 0; i < size; ++ i)
        {
            for(int j = 0; j < size; ++ j)
            {
                if(board[i][j] == '.')
                {
                    for(char k = '1'; k <= '9'; ++ k)
                    {
                        if(isValidItem(i, j, k, size, board))
                        {
                            board[i][j] = k;
                            if(backstrack(board)) { return true; }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidItem(int row, int col, char k, int size, vector<vector<char>> &board)
    {
        for(int i = 0; i < size; ++ i)
        {
            if(board[i][col] == k)
            {
                return false;
            }
        }
        for(int j = 0; j < size; ++ j)
        {
            if(board[row][j] == k)
            {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow; i < startRow + 3; ++ i)
        {
            for(int j = startCol; j < startCol + 3; ++ j)
            {
                if(board[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true; 
    }
};


void print(vector<vector<char>>& board)
{
    for(auto i : board)
    {
        cout << '[';
        int mark = 1;
        for(auto j : i)
        {

            if(mark != i.size())
            {
                cout << j << ' ';
                ++ mark;
                continue;
            }
            cout << j;
        }
        cout << ']';
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> charVec{   
                                    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
                                };
    print(charVec);
    Solution().solveSudoku(charVec);
    print(charVec);
    return 0;
}