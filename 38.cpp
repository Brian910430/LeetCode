#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string s = countAndSay(n - 1);
        string ans = "";
        int l = s.length();

        for (int i = 0; i < l;)
        {
            int j = i;
            for (; j < l && s[i] == s[j]; j++)
                ;
            ans.push_back('0' + j - i);
            ans.push_back(s[i]);
            i = j;
        }
        return ans;
    }
};