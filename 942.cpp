#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.length();
        int mid = 0;
        vector<int> ans = vector<int>(n + 1);
        for (auto i : s)
            if (i == 'D')
                mid++;
        int left = mid - 1;
        int right = mid + 1;
        ans[0] = mid;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
                ans[i + 1] = left--;
            if (s[i] == 'I')
                ans[i + 1] = right++;
        }
        return ans;
    }
};