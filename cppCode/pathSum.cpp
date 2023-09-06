#include <iostream>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if(root == nullptr) { return result; }
        vector<int> pathNode;
        pathNode.push_back(root->val);
        recursive(root, targetSum - root->val, result, pathNode);
        return result;
    }
    void recursive(TreeNode* root, int remaining, vector<vector<int>> &result, vector<int> &path)
    {
        if(root->left == nullptr && root->right == nullptr && remaining == 0)
        {
            result.push_back(path);
            return;
        } else if(root->left == nullptr && root->right == nullptr && remaining != 0) {
            return;
        }

        if(root->left != nullptr)
        {
            path.push_back(root->left->val);
            recursive(root->left, root->val-remaining, result, path);
            path.pop_back();
        }
        if(root->right != nullptr)
        {
            path.push_back(root->right->val);
            recursive(root->right, root->val - remaining, result, path);
            path.pop_back();
        }
        return;
    }
};

int main()
{
    return 0;
}