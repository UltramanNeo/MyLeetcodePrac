#include <iostream>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == nullptr) { return result; }
        vector<int> pathNode;
        transverse(root, result, pathNode);
        return result;

    }
    void transverse(TreeNode *root, vector<string> result, vector<int> pathNode)
    {
        pathNode.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            int size = pathNode.size();
            string resultStr;
            for(int i = 0; i < size - 1; ++ i)
            {
                resultStr += to_string(pathNode[i]);
                resultStr += "->";
            }
            resultStr += to_string(pathNode[size - 1]);
            result.push_back(resultStr);
        }

        if(root->left!= nullptr) {
            transverse(root->left, result, pathNode);
            pathNode.pop_back();
        }
        if(root->right != nullptr)
        {
            transverse(root->right, result, pathNode);
            pathNode.pop_back();
        }

        return;
    }
};


int main()
{
    return 0;
}