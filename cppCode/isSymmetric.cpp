#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) { return true; }
        queue<TreeNode*> tnQueue;
        tnQueue.push(root->left);
        tnQueue.push(root->right);
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        while(!tnQueue.empty())
        {
            left = tnQueue.front();
            tnQueue.pop();
            right = tnQueue.front();
            tnQueue.pop();
            if(left == nullptr && right == nullptr)
            {
                continue;
            }
            if(left == nullptr || right == nullptr || left->val != right->val)
            {
                return false;
            }
            tnQueue.push(left->left);
            tnQueue.push(right->right);
            tnQueue.push(left->right);
            tnQueue.push(right->left);
        }
        return true;
    }
};

int main()
{
    return 0;
}