#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        vector<int> group;
        int count = 1;
        int ans = 0;

        for (int i = 1; i < s.length(); i++)
            if (s[i] != s[i - 1])
            {
                group.push_back(count);
                count = 1;
            }
            else
                count++;
        group.push_back(count);
        if (group.size() < 2)
            return 0;

        for (int i = 1; i < group.size(); i++)
            ans += min(group[i], group[i - 1]);
        return ans;
    }
};