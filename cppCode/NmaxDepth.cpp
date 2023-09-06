#include <iostream>
#include <stack>
#include <queue>
#include "TreeNode.h"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // int maxDepth(Node* root) {
    //     int depth = 0;
    //     if(root == nullptr) { return 0; }
    //     int size = root->children.size();
    //     for(int i = 0; i < size; ++ i)
    //     {
    //         depth = max(depth, maxDepth(root->children[i]));
    //     }
    //     return depth + 1;
    // }

    int maxDepth(Node *root)
    {
        int result = 0;
        if(root == nullptr) { return result; }
        queue<Node*> tnQueue;
        tnQueue.push(root);
        int size = 0, subSize = 0;
        while(!tnQueue.empty())
        {
            size = tnQueue.size();
            ++ result;
            for(int i = 0; i < size; ++ i)
            {
                root = tnQueue.front();
                tnQueue.pop();
                subSize = root->children.size();
                for(int j = 0; j < subSize; ++ j)
                {
                    if(root->children[i] != nullptr) {
                        tnQueue.push(root->children[i]);
                    }
                }
            }
        }
        return result;
    }
};


int main()
{

    return 0;
}