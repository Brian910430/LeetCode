#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string s = to_string(x);
        int n = s.length() - 1;
        if (!n)
            return true;

        for (int i = 0, j = n; i <= j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};