#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0, j = 0; i < g.size() && j < s.size(); i++, j++)
        {
            while (j < s.size() && g[i] > s[j])
                j++;
            if (j < s.size())
                ans++;
        }
        return ans;
    }
};