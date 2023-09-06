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
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> result;
        work(root, result);
    }
    void work(TreeNode *cur, vector<int> &result)
    {
        if(cur == nullptr)
        {
            return;
        }
        result.push_back(cur->val);
        work(cur->left, result);
        work(cur->right, result);
        return;
    }

    vector<int> preorderTraversal(TreeNode *root){
        // 做两种方式，此为1
        // vector<int> result;
        // if(root == nullptr)
        // {
        //     return result;
        // } else if(root->left == nullptr && root->right == nullptr)
        // {
        //     result.push_back(root->val);
        //     return result;
        // }
        // stack<TreeNode*> tnStack;
        // do
        // {
        //     if(!tnStack.empty())
        //     {
        //         root = tnStack.top();
        //         tnStack.pop();
        //     }
        //     result.push_back(root->val);
        //     if(root->right != nullptr) { tnStack.push(root->right); }
        //     if(root->left != nullptr) { tnStack.push(root->left); }
        // }while(!tnStack.empty());
        // return result;

        // 此为2
        vector<int> result(0);
        if(root == nullptr)
        {
            return result;
        }
        stack<TreeNode*> tnStack;
        tnStack.push(root);
        while(!tnStack.empty())
        {
            root = tnStack.top();
            tnStack.pop();
            result.push_back(root->val);
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