#include <iostream>
#include "TreeNode.h"
#include <stack>
#include <vector>
#include <queue>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) { return nullptr; }
        int maxIndex = 0;
        for(int i = 0; i < size; ++ i)
        {
            if(nums[maxIndex] < nums[i])
            {
                maxIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);
        vector<int> lNums(nums.cbegin(), nums.cbegin() + maxIndex);
        vector<int> rNums(nums.cbegin() + maxIndex + 1, nums.cend());

        root->left = constructMaximumBinaryTree(lNums);
        root->right = constructMaximumBinaryTree(rNums);

        return root;
    }
};


int main()
{
    return 0;
}