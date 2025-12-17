#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        int count = 0;
        int ans = 0;

        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '1')
                count++;
            if (s[i] == '1' && s[i + 1] == '0')
                ans += count;
        }
        return ans;
    }
};