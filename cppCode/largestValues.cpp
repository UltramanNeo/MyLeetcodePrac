#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) { return result; }
        queue<TreeNode*> tnQueue;
        tnQueue.push(root);
        int size = 0, max = 0;
        while(!tnQueue.empty())
        {
            size = tnQueue.size();
            max = INT32_MIN;
            for(int i = 0; i < size; ++ i)
            {
                root = tnQueue.front();
                tnQueue.pop();
                if(max < root->val)
                {
                    max = root->val;
                }
                if(root->left != nullptr) { tnQueue.push(root->left); }
                if(root->right != nullptr) { tnQueue.push(root->right); }
            }
            result.push_back(max);
            size = 0;
        }
        return result;
    }
};

int main()
{
    return 0;
}