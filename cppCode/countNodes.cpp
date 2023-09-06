#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    int countNodes(TreeNode* root) {
        int result = 0;
        if(root == nullptr) { return result; }

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int lLength = 0, rLength = 0;
        while(left != nullptr)
        {
            left = left->left;
            ++ lLength;
        }
        while (right != nullptr)
        {
            right = right->left;
            ++ rLength;
        }
        if(lLength == rLength)
        {
            return 2 << lLength - 1;
        }

        return countNodes(left) + countNodes(right) + 1;
        
    }
};

int main()
{
    return 0;
}