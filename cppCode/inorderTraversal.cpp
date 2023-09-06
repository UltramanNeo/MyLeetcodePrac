#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     work(root, result);
    //     return result;
    // }
    // void work(TreeNode *cur, vector<int> &result)
    // {
    //     if(cur == nullptr)
    //     {
    //         return;
    //     }
    //     work(cur->left, result);
    //     result.push_back(cur->val);
    //     work(cur->right, result);
    //     return;
    // }

    // 方法2
    vector<int> result;
    stack<TreeNode *> tnStack;
    while (root != nullptr || !tnStack.empty())
    {
        if (root != nullptr)
        {
            tnStack.push(root);
            root = root->left;
        }
        else
        {
            root = tnStack.top();
            tnStack.pop();
            result.push_back(root->val);
            root = root->right;
        }
    }
    return result;
};

int main()
{
    return 0;
}