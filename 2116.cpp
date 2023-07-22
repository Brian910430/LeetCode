#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        if (s.length() % 2)
            return false;

        int count = 0;
        int reverse = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (locked[i] == '0' || s[i] == '(')
                count++;
            else if (s[i] == ')')
                count--;
            if (count < 0)
                return false;
        }
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (locked[i] == '0' || s[i] == ')')
                reverse++;
            else if (s[i] == '(')
                reverse--;
            if (reverse < 0)
                return false;
        }
        return true;
    }
};