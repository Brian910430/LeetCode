#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int left = s.length() - 1;
        int right = 0;
        while (left >= 0 && s[left] == ' ')
            left--;
        right = left;
        while (left >= 0 && s[left] != ' ')
            left--;
        return right - left;
    }
};