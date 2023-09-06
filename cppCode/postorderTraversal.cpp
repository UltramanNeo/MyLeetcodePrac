#include <iostream>
#include <vector>
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
// class Solution
// {
// public:
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         // vector<int> result;
//         // work(root, result);
//         // return result;
//         vector<int> result;
//         if (root == nullptr)
//         {
//             return result;
//         }
//         stack<TreeNode *> tnStack;
//         do
//         {
//             if (!tnStack.empty())
//             {
//                 root = tnStack.top();
//                 tnStack.pop();
//                 result.push_back(root->val);
//             }
//             if (root->right != nullptr)
//             {
//                 tnStack.push(root->right);
//             }
//             if (root->left != nullptr)
//             {
//                 tnStack.push(root->left);
//             }
//         } while (!tnStack.empty());
//         return result;
//     }
//     // void work(TreeNode *cur, vector<int> &result)
//     // {
//     //     if(cur == nullptr)
//     //     {
//     //         return;
//     //     }
//     //     work(cur->left, result);
//     //     work(cur->right, result);
//     //     result.push_back(cur->val);
//     // }
// };
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        // vector<int> result;
        // work(root, result);
        // return result;

        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        stack<TreeNode *> tnStack;
        TreeNode *mark = nullptr;
        // do
        // {
        //     if (root->right != nullptr)
        //     {
        //         tnStack.push(root->right);
        //     }
        //     if (root->left != nullptr)
        //     {
        //         tnStack.push(root->left);
        //     }
        //     while (!tnStack.empty())
        //     {
        //         if (tnStack.top()->left == nullptr)
        //         {
        //             if (tnStack.top()->right == nullptr || tnStack.top() == mark)
        //             {
        //                 result.push_back(tnStack.top()->val);
        //                 mark = tnStack.top();
        //                 tnStack.pop();
        //                 if (!tnStack.empty())
        //                 {
        //                     root = tnStack.top();
        //                 }
        //                 else
        //                 {
        //                     return result;
        //                 }
        //             }
        //             else
        //             {
        //                 root = tnStack.top()->right;
        //             }
        //         }
        //         else
        //         {
        //             root = tnStack.top();
        //         }
        //     }
        // } while (!tnStack.empty());
        do {
            while(root != nullptr)
            {
                tnStack.push(root);
                root = root->left;
            }
            // mark = nullptr;
            while(!tnStack.empty())
            {
                root = tnStack.top();
                tnStack.pop();
                if(root->right == nullptr || root->right == mark)
                {
                    mark = root;
                    result.push_back(root->val);
                } else {
                    tnStack.push(root);
                    root = root->right;
                    break;
                }
            }
        } while(!tnStack.empty());


        return result;
    }
};
void print(vector<int> input)
{
    auto cur = input.cbegin();
    auto end = input.cend();
    for(; cur != end; ++ cur)
    {
        cout << *cur << " " << ends;
    }
    return;
}

int main()
{
    vector<int> a;
    print(Solution().postorderTraversal(a));
    return 0;
}