#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;
        int temp = 0;

        for (auto i : s)
        {
            if (i == '(')
            {
                temp++;
                ans = max(ans, temp);
            }
            else if (i == ')')
                temp--;
        }
        return ans;
    }
};