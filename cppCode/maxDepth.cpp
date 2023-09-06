#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) { return 0; }
        queue<TreeNode*> tnQueue;
        tnQueue.push(root);
        int depth = 0;
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
            }
            ++ depth;
            size = 0;
        }
        return depth;
    }
};
int main()
{
    return 0;
}