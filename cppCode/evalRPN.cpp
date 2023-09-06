#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tkStack;
        int size = tokens.size();
        int nums1 = 0, nums2 =0;
        for(int i = 0; i < size; ++ i)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                nums1 = static_cast<int>(tkStack.top());
                tkStack.pop();
                nums2 = static_cast<int>(tkStack.top());
                tkStack.pop();
                switch (static_cast<int>(tokens[i][0]))
                {
                case '+':
                    nums2 += nums1;
                    break;
                case '-':
                    nums2 -= nums1;
                    break;
                case '*':
                    nums2 *= nums1;
                    break;
                default:
                    nums2 /= nums1;
                    break;
                }
            } else {
                tkStack.push(stoi(tokens[i]));
            }
        }
        return nums2;
    }

};

int main()
{
    vector<string> s{"1", "2", "-"};
    cout << Solution().evalRPN(s) << ends;
    return 0;
}