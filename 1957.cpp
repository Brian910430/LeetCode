#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans = s.substr(0, 2);
        char prev = s[1];
        char prevPrev = s[0];

        for (int i = 2; i < s.length(); i++)
        {
            if (prev != prevPrev || prev != s[i])
            {
                ans.push_back(s[i]);
                prevPrev = prev;
                prev = s[i];
            }
        }
        return ans;
    }
};