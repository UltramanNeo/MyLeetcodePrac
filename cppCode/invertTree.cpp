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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> tnQueue;
        if(root == nullptr) { return root; }
        tnQueue.push(root);
        TreeNode* cur = nullptr;
        int size = 0;
        TreeNode* tmp = nullptr;

        while(!tnQueue.empty())
        {
            size = tnQueue.size();
            for(int i = 0; i < size; ++ i)
            {
                cur = tnQueue.front();
                tnQueue.pop();
                swap(cur->left, cur->right);
                if(cur->left != nullptr) { tnQueue.push(cur->left); }
                if(cur->right!= nullptr) { tnQueue.push(cur->right); }
            }
        }
        return root;
    }
};

int main()
{
    return 0;
}