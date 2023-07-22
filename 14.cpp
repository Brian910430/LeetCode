#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        char now;
        for (int i = 0; i < strs[0].length(); i++)
        {
            now = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
                if (i == strs[j].length() || strs[j][i] != now)
                    return ans;
            ans += now;
        }
        return ans;
    }
};