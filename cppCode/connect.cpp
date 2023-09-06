#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) { return root; }
        queue<Node*> nQueue;
        Node *pre = root;
        Node *cur = root;
        int size = 0;
        nQueue.push(root);
        while(!nQueue.empty())
        {
            pre = nQueue.front();
            size = nQueue.size();
            for(int i = 0; i < size; ++ i)
            {
                cur = nQueue.front();
                nQueue.pop();
                if(pre != cur)
                {
                    pre->next = cur;
                    pre = pre->next;
                }
                if(cur->left != nullptr) { nQueue.push(cur->left); }
                if(cur->right != nullptr) { nQueue.push(cur->right); }
            }
            size = 0;
        }
        return root;
    }
};

int main()
{
    return 0;
}