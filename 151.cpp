#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int index = s.length() - 1;
        string ans = "";
        while (s[index] == ' ')
            index--;

        while (1)
        {
            while (index >= 0 && s[index] == ' ')
                index--;
            if (index < 0)
                break;
            int start = index;
            while (start >= 0 && s[start] != ' ')
                start--;
            ans += s.substr(start + 1, index - start);
            ans += " ";
            index = start;
        }
        ans = ans.substr(0, ans.length() - 1);
        return ans;
    }
};