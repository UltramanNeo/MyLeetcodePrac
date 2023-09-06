#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) { return 0; }
        queue<TreeNode*> tnQueue;
        tnQueue.push(root);
        int depth = 1;
        int min = INT32_MAX;
        int size = 0;
        while(!tnQueue.empty())
        {
            size = tnQueue.size();
            for(int i = 0; i < size; ++ i)
            {
                root = tnQueue.front();
                tnQueue.pop();
                if(root->left != nullptr) { tnQueue.push(root->left); }
                if(root->right!= nullptr) { tnQueue.push(root->right); }
                if(root->left == nullptr && root->right == nullptr)
                {
                    if(min >= depth)
                    {
                        min = depth;
                    }
                }
            }
            size = 0;
            ++ depth;
        }
        return min;
    }
};
int main()
{
    return 0;
}