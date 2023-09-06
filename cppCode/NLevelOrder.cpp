#include <iostream>
#include <queue>
#include <vector>
using namespace std;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root == nullptr) { return result; }
        queue<Node*> nStack;
        nStack.push(root);
        int size = 0;
        vector<int> subVec;
        while(!nStack.empty())
        {
            size = nStack.size();
            for(int i = 0; i < size; ++ i)
            {
                root = nStack.front();
                nStack.pop();
                subVec.push_back(root->val);
                for(int j = 0; j < root->children.size(); ++ j)
                {
                    nStack.push(root->children[j]);
                }
            }
            result.push_back(subVec);
            size = 0;
            subVec.clear();
        }
        return result;
    }
};

int main()
{
    return 0;
}