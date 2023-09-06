#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    // string removeDuplicates(string s) {
    //     stack<char> sStack;
    //     for(int i = 0; i < s.size(); ++ i)
    //     {
    //         if(sStack.empty() || s[i] != sStack.top())
    //         {
    //             sStack.push(s[i]);
    //         } else
    //         {
    //             sStack.pop();
    //         }
    //     }
    //     s.clear();
    //     while(!sStack.empty())
    //     {
    //         s.push_back(sStack.top());
    //         sStack.pop();
    //     }
    //     reverse(s.begin(), s.end());
    //     return s;
    // }
    string removeDuplicates(string s) {
        string result = "";
        // int size = s.size();
        auto ptr = s.begin();
        auto ptrEnd = s.end();
        for(; ptr != ptrEnd; ++ ptr)
        {
            if(result.empty() || *ptr != result.back())
            {
                result.push_back(*ptr);
            } else {
                result.pop_back();
            }
        }
        return result;
    }
};

int main()
{
    string a = "abcdeffg";
    cout << Solution().removeDuplicates(a) << ends;
    return 0;
}