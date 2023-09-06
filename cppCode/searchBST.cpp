#include <iostream>
#include <vector>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        // while(root != nullptr)
        // {
        //     if(root->val < val)
        //     {
        //         root = root->right;
        //         continue;
        //     } else if(root->val > val) {
        //         root = root->left;
        //     } else {
        //         return root;
        //     }
        // }
        // return root;

        if(root == nullptr || root->val == val)
        {
            return root;
        }
        TreeNode *result = nullptr;
        if(root->val < val) 
        { 
            return searchBST(root->right, val); 
        } else {
            return searchBST(root->left, val);
        }
    }
};

int main()
{
    return 0;
}