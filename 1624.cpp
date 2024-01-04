#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<vector<int>> dict(26, vector<int>(2, -1));
        int n = s.length();
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if (dict[s[i] - 'a'][0] == -1)
                dict[s[i] - 'a'][0] = i;
            dict[s[i] - 'a'][1] = max(dict[s[i] - 'a'][1], i);
        }
        for (int i = 0; i < 26; i++)
            if (dict[i][0] != -1)
                ans = max(ans, dict[i][1] - dict[i][0] - 1);
        return ans;
    }
};