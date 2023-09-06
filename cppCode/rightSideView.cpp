#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> tnQueue;
        tnQueue.push(root);
        int size = 0;
        while (!tnQueue.empty())
        {
            size = tnQueue.size();
            for (int i = 0; i < size; ++i)
            {
                if (i == size - 1)
                {
                    root = tnQueue.front();
                    tnQueue.pop();
                    result.push_back(root->val);
                    if (root->left != nullptr)
                    {
                        tnQueue.push(root->left);
                    }
                    if (root->right != nullptr)
                    {
                        tnQueue.push(root->right);
                    }
                }
                else
                {
                    root = tnQueue.front();
                    tnQueue.pop();
                    if (root->left != nullptr)
                    {
                        tnQueue.push(root->left);
                    }
                    if (root->right != nullptr)
                    {
                        tnQueue.push(root->right);
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}