#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizedStringLength(string s)
    {
        int ans = 0;
        set<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (st.count(s[i]) == 0)
            {
                ans++;
                st.insert(s[i]);
            }
        }
        return ans;
    }
};