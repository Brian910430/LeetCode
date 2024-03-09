#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int l = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            ans.push_back('0');
            if (s[i] == '1')
                l++;
        }
        for (int i = 1; i < l; i++)
            ans[i - 1] = '1';
        ans[ans.size() - 1] = '1';
        return ans;
    }
};