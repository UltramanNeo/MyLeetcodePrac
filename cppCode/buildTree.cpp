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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) { return nullptr; }
        int rootVal = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootVal);

        if(postorder.size() == 1) {
            return root;
        }
        int inorderPos = 0;
        int inorderSize = inorder.size();
        for(; inorderPos < inorderSize; ++ inorderPos)
        {
            if(inorder[inorderPos] == rootVal)
            {
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + inorderPos);
        vector<int> rightInorder(inorder.begin() + inorderPos + 1, inorder.end());

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + inorderPos);
        vector<int> rightPostorder(postorder.begin() + inorderPos, postorder.end() - 1);

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};


int mian()
{
    return 0;
}