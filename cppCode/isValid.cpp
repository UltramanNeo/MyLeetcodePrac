#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if(size % 2 != 0)
        {
            return false;
        }
        stack<char> sStack;
        for(int i = 0; i < size; ++ i)
        {
            if(s[i] == '(') { sStack.push(')'); }
            else if(s[i] == '[') { sStack.push(']'); }
            else if(s[i] == '{') { sStack.push('}'); }
            else if(sStack.empty() || s[i] != sStack.top()) {
                return false;
            }
            else { sStack.pop(); }
        }
        retrun sStack.empty();
    }
};
int main()
{
    string s = "(]";
    cout << Solution().isValid(s) << ends;
    return 0;
}