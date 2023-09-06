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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 迭代法
        // vector<vector<int>> tnVec;
        // if(root == nullptr)
        // {
        //     return tnVec;
        // }
        // queue<TreeNode*> tnQue;
        // tnQue.push(root);
        // while(!tnQue.empty())
        // {
        //     vector<int> subResult;
        //     int size = tnQue.size();
        //     for(int i = 0; i < size; ++ i)
        //     {
        //         root = tnQue.front();
        //         subResult.push_back(root->val);
        //         tnQue.pop();
        //         if(root->left != nullptr) { tnQue.push(root->left); }
        //         if(root->right!= nullptr) { tnQue.push(root->right); }
        //     }
        //     tnVec.push_back(subResult);
        // }
        // return tnVec;


        // 递归法
        vector<vector<int>> result;
        int high = 0;
        order(root, result, high);
        return result;
    }
};
void order(TreeNode *root, vector<vector<int>> &result, int high)
{
    if(root == nullptr) {
        return;
    }
    result[high].push_back(root->val);
    if(root->left != nullptr) {
        order(root->left, result, high + 1);
    }
    if(root->right != nullptr) {
        order(root->right, result, high + 1);
    }
}

int main()
{
    return 0;
}