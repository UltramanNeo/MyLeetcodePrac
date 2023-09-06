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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) { return true; }
        TreeNode *node = nullptr;
        if(root->left == nullptr && root->right != nullptr && root->val < root->right->val)
        {
            node = root->right->left;
            while(node != nullptr && node->val > root->val)
            {
                node = node->left;
            }
            if(node == nullptr) {
                return isValidBST(root->right);
            } else {
                return false;
            }
        }
        if(root->left != nullptr && root->right == nullptr && root->val > root->left->val)
        {
            node = root->left->right;
            while(node != nullptr && node->val < root->val)
            {
               node = node->right;
            } 
            if(node == nullptr) {
                return isValidBST(root->left);
            } else {
                return false;
            }
        }
        if(root->left != nullptr && root->right != nullptr && (root->val < root->right->val) && (root->val > root->left->val))
        {
            node = root->right->left;
            while(node != nullptr && node->val > root->val)
            {
                node = node->left;
            }
            if(node != nullptr) {
                return false;
            }

            node = root->left->right;
            while(node != nullptr && node->val < root->val)
            {
               node = node->right;
            } 
            if(node != nullptr) {
                return false;
            }
            
            return isValidBST(root->left) && isValidBST(root->right);
        }
        return false;
    }
};

int main()
{
    return 0;
}