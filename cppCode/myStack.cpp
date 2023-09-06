#include <iostream>
#include <queue>
using namespace std;
class MyStack{
public:
    MyStack(): ptr1(&que1), ptr2(&que2){

    }
    
    void push(int x) {
        if(ptr1->empty())
        {
            ptr1->push(x);
            return;
        } else {
            while(!ptr2->empty())
            {
                ptr1->push(ptr2->front());
                ptr2->pop();
            }
            ptr2->push(x);
        }
        return;
    }
    
    int pop() {
        int front = 0;
        if(ptr2->empty())
        {
            front = ptr1->front();
            ptr1->pop();
            return front;
        } else {
            front = ptr2->front();
            ptr2->pop();
            while(ptr1->size() != 1 && !ptr1->empty())
            {
                ptr2->push(ptr1->front());
                ptr1->pop();
            }
            swap(ptr1, ptr2);
        }
        return front;
    }
    
    int top() {
        if(ptr2->empty())
        {
            return ptr1->front();
        }
        return ptr2->front();
    }
    
    bool empty() {
        return ptr1->empty() && ptr2->empty();
    }

private:
    queue<int> que1;
    queue<int> que2;
    queue<int> *ptr1;
    queue<int> *ptr2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
    return 0;
}