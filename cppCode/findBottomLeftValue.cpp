#include <iostream>
#include <queue>
#include <stack>
#include "TreeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int depth = 1, minDepth = 0;
        return recursion(root, depth, minDepth);
        
    }
    int recursion(TreeNode *root, int depth, int &minDepth)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            if(minDepth < depth)
            {
                minDepth = depth;
                return root->val;
            }
        } else if(root->left == nullptr) {
            return recursion(root->right, depth + 1, minDepth);
        } else if(root->right == nullptr) {
            return recursion(root->left, depth + 1, minDepth);
        } else {
            int lNum = recursion(root->left, depth + 1, minDepth);
            int lMinDepth = minDepth;
            int rNum = recursion(root->right, depth + 1, minDepth);
            int rMinDepth = minDepth;
            if(lMinDepth < rMinDepth)
            {
                return rNum;
            } else {
                return lNum;
            }
        }
        return INT32_MIN;
    }
};

int main()
{
    return 0;
}