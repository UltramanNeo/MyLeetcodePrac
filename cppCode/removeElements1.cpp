#include <iostream>
#include "ListNode.h"
// #include <queue>
using namespace std;
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp = nullptr;
        // 针对头节点做特殊处理
        while (head != nullptr && head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        if(head == nullptr)
        {
            return head;
        }
        ListNode *tmp1 = head->next;
        while (tmp1 != nullptr)
        {
            if(tmp1->val == val)
            {
                ListNode *tmp2 = tmp1->next;
                tmp1->next = tmp1->next->next;
                delete tmp2;
            } else {
                tmp1 = tmp1->next;
            }
        }
        return head;
    }

};
int main()
{   
    
    return 0;
}