#include <iostream>
#include "TreeNode.h"
#include <stack>
#include <vector>
#include <queue>
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // if(root1 == nullptr) { return root2; }
        // if(root2 == nullptr) { return root1; }
        // TreeNode *root = new TreeNode(root1->val + root2->val);
        // root->left = mergeTrees(root1->left, root2->left);
        // root->right = mergeTrees(root1->right, root2->right);

        // return root;

        if(root1 == nullptr) { return root2; }
        if(root2 == nullptr) { return root1; }
        queue<TreeNode*> tnQueue;
        tnQueue.push(root2);
        tnQueue.push(root1);
        TreeNode *node1 = nullptr;
        TreeNode *node2 = nullptr;
        TreeNode *node = new TreeNode;
        TreeNode *cur = node;
        while(!tnQueue.empty())
        {
            node1 = tnQueue.front();
            tnQueue.pop();
            node2 = tnQueue.front();
            tnQueue.pop();

            // cur->val = node1->val + node2->val;
            TreeNode *nodeLeft = new TreeNode;
            TreeNode *nodeRight = new TreeNode;
            if(node1->left != nullptr && node2->left != nullptr)
            {
                cur->val = node1->val + node2->val;
                tnQueue.push(node1->left);
                tnQueue.push(node2->left);
                cur->left = nodeLeft;
                cur = cur->left;
            }
            if(node1->right != nullptr && node2->right != nullptr)
            {
                cur->val = node1->val + node2->val;
                tnQueue.push(node1->right);
                tnQueue.push(node2->right);
                cur->right = nodeRight;
                cur = cur->right;

            }
            if(node1->left != nullptr && node2->left == nullptr)
            {
                cur->val = node1->val;
                cur->left = nodeLeft;
                cur = cur->left;
            }
            if(node1->right == nullptr && node2->right != nullptr)
            {
                cur->val = node2->val;
                cur->right = nodeRight;
                cur = cur->right;
            }

            
        }
        return node;
    }
};


int main()
{
    return 0;
}