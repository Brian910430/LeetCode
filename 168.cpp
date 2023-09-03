#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber > 0)
        {
            int remain = (--columnNumber) % 26;
            ans += 'A' + remain;
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};