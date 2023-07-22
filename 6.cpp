#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string ans = "";
        int n = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = i; j < s.size(); j += n)
            {
                ans += s[j];
                if (i != 0 && i != numRows - 1 && j + n - 2 * i < s.size())
                    ans += s[j + n - 2 * i];
            }
        }
        return ans;
    }
};