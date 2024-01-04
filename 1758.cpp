#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int ans1 = 0;
        int ans2 = 0;
        int l = s.length();

        for (int i = 0; i < l; i++)
            if (i % 2 == 0 && s[i] == '1')
                ans1++;
            else if (i % 2 == 1 && s[i] == '0')
                ans1++;
        for (int i = 0; i < l; i++)
            if (i % 2 == 0 && s[i] == '0')
                ans2++;
            else if (i % 2 == 1 && s[i] == '1')
                ans2++;
        return min(ans1, ans2);
    }
};