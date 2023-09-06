#include <iostream>
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
    int sumOfLeftLeaves(TreeNode* root) {
        // if(root == nullptr)
        // {
        //     return 0;
        // }
        // int lNum = 0, rNum = 0;
        // if(root->left == nullptr && root->right == nullptr) { return 0; }
        // if(root->left != nullptr && root->left == nullptr && root->right == nullptr)
        // {
        //     lNum = root->left->val;
        // } else {
        //     lNum = sumOfLeftLeaves(root->left);
        // }

        // rNum = sumOfLeftLeaves(root->right);

        // return lNum + rNum;

        int result = 0;
        if(root == nullptr) { return 0; }
        stack<TreeNode*> tnStack;
        tnStack.push(root);
        while(!tnStack.empty())
        {
            root = tnStack.top();
            tnStack.pop();
            if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            {
                result += root->left->val;
            }

            if(root->right != nullptr) { tnStack.push(root->right); }
            if(root->left != nullptr) { tnStack.push(root->left); }
        }
        return result;
    }
};

int main()
{
    return 0;
}