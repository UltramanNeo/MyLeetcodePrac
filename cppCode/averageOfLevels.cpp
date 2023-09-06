#include <iostream>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == nullptr) { return result; }
        queue<TreeNode*> tnQueue;
        tnQueue.push(root);
        int size = 0;
        double sum = 0;
        while(!tnQueue.empty())
        {
            size = tnQueue.size();
            for(int i = 0; i < size; ++ i)
            {
                root = tnQueue.front();
                tnQueue.pop();
                sum += root->val;
                if(root->left != nullptr) { tnQueue.push(root->left); }
                if(root->right != nullptr) { tnQueue.push(root->right); }
            }
            result.push_back(sum / size);
            sum = size = 0;
        }
        return result;
    }
};

int main()
{
    return 0;
}