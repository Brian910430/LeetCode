#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans = "";
        int n = s.length();
        if (n == 0)
            return ans;
        vector<vector<int>> capable(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            capable[i][i] = 1;
        ans = s.substr(n - 1);

        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1])
            {
                capable[i][i + 1] = 1;
                ans = s.substr(i, 2);
            }

        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                if (s[i] == s[j])
                {
                    if (capable[j + 1][i - 1])
                    {
                        capable[j][i] = 1;
                        if (i - j + 1 >= ans.length())
                            ans = s.substr(j, i - j + 1);
                    }
                }
        return ans;
    }
};