#include <iostream>
#include "ListNode.h"
using namespace std;
class Solution
{
public:
    ListNode *reverseList2(ListNode *head)
    {
        ListNode *tmp = nullptr;
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur != nullptr)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    ListNode *reverseList(ListNode *head)
    {
        return reverse(nullptr, head);
    }
    ListNode *reverse(ListNode* pre, ListNode* cur)
    {
        if(cur == nullptr)
        {
            return pre;
        }
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
    
};

int main()
{
    return 0;
}