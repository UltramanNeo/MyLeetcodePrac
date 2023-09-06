#include <iostream>
using namespace std;
struct LinkedNode
{
    int val;
    LinkedNode *next;
    LinkedNode(int init = 0) : val(init), next(nullptr) {}
};

// 这道题目设计链表的五个接口：
// 构造函数，虚拟头结点成员
// 获取链表第index个节点的数值
// 在链表的最前面插入一个节点
// 在链表的最后面插入一个节点
// 在链表第index个节点前面插入一个节点
// 删除链表的第index个节点
class MyLinkedList
{
public:
    MyLinkedList() : dummyHead(new LinkedNode(0)), size(0)
    {
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        LinkedNode *cur = dummyHead;
        for (; index + 1 != 0; --index)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        ++ size;
    }

    void addAtTail(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = dummyHead;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->next = nullptr;
        ++ size;
    }

    void addAtIndex(int index, int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = dummyHead;
        if (index > size)
        {
            return;
        }
        else if (index < 0)
        {
            index = 0;
        }
        while (index > 0)
        {
            cur = cur->next;
            --index;
        }
        newNode->next = cur->next;
        cur->next = newNode;

        ++ size;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        LinkedNode *cur = dummyHead;
        while (index > 0)
        {
            cur = cur->next;
            --index;
        }
        LinkedNode *cur2 = cur->next;
        cur->next = cur->next->next;
        delete cur2;

        -- size;
    }
    void print()
    {
        LinkedNode *cur = dummyHead;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << " " << ends;
            cur = cur->next;
        }
        return;
        
    }
private:
    LinkedNode *dummyHead;
    int size;
};


int main()
{
    MyLinkedList *obj = new MyLinkedList();
    int param_1 = obj->get(1);
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    obj->deleteAtIndex(2);
    return 0;
}