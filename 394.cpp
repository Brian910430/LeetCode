#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> strs;
        stack<int> nums;
        string ans = "";

        for (int index = 0; index < s.length(); index++)
        {
            if ('1' <= s[index] && s[index] <= '9')
            {
                int n = 0;
                while ('0' <= s[index] && s[index] <= '9')
                {
                    n = n * 10 + s[index] - '0';
                    index++;
                }
                index--;
                nums.push(n);
            }
            else if (s[index] == '[')
            {
                strs.push(ans);
                ans = "";
            }
            else if (s[index] == ']')
            {
                string temp = strs.top();
                int n = nums.top();
                nums.pop();
                strs.pop();
                while (n--)
                    temp += ans;
                ans = temp;
            }
            else
                ans += s[index];
        }
        return ans;
    }
};