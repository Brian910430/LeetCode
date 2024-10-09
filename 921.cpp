#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int ans = 0;
        stack<char> record;

        for (auto i : s)
        {
            if (i == '(')
                record.push(i);
            else if (i == ')' && record.size())
                record.pop();
            else
                ans++;
        }
        return ans + record.size();
    }
};