#include <iostream>
#include "ListNode.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next != nullptr || cur->next->next != nullptr)
        {
            ListNode *tmpN = cur->next;
            ListNode *tmpNNN = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmpN;
            cur->next->next = tmpNNN;
        }
        // head = dummyHead->next;
        // delete dummyHead;
        // return head;
        return dummyHead->next;
    }
};

void print(ListNode *head) {
    ListNode *tmp = head;
    ListNode *tmp2 = nullptr;
    while(tmp != nullptr)
    {
        cout << tmp->val << " " << ends;
        tmp2 = tmp;
        tmp = tmp->next;
        delete tmp2;
    }
}

int main()
{
    ListNode *tmp = nullptr;
    ListNode *start = new ListNode(0);
    tmp = start;
    for(int i = 1; i <= 5; ++ i)
    {
        ListNode *node = new ListNode(i);
        tmp->next = node;
        tmp = tmp->next;
    }
    Solution().swapPairs(start);
    print(start);
    return 0;
}