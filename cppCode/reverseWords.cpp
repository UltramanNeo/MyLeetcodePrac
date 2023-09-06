#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        void removeExtraSpace(string &s);
        removeExtraSpace(s);
        reverse(s.begin(), s.end());
        int size = s.size();
        int slow = 0;
        for(int i = slow; i <= size; ++ i)
        {
            if(i == size || s[i] == ' ')
            {
                reverse(s.begin() + slow, s.begin() + i);
                slow = i + 1;
            }
        }
        // reverse(s.begin() + slow, s.end());
        return s;
    }
};
void removeExtraSpace(string &s)
{
    int i = 0, slow = 0;
    int size = s.size();
    for(; i < size; ++ i)
    {
        if(s[i] == ' ')
        {
            continue;
        } else {
            if(slow != 0)
            {
                s[slow ++] = ' ';
            }
            while(i < size && s[i] != ' ')
            {
                s[slow ++] = s[i ++];
            }
        }
    }
    s.resize(slow);
}
int main()
{
    void removeExtraSpace(string &s);
    string s = "       12        345       ";
    // removeExtraSpace(s);
    cout << Solution().reverseWords(s) << ends;
    return 0;
}