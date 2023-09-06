#include <iostream>
#include <stack>
#include <queue>
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
    bool isBalanced(TreeNode* root) {
        int result = getHeight(root);
        return result != -1 ? true : false;
    }
    int getHeight(TreeNode *root)
    {
        if(root == nullptr) { return 0; }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int lHeight = 0, rHeight = 0;
        lHeight = getHeight(left);
        rHeight = getHeight(right);
        if(lHeight - rHeight > 1 || rHeight - lHeight > 1)
        {
            return -1;
        } else {
            return 1 + max(lHeight, rHeight);
        }
    }
};

int main()
{
    return 0;
}