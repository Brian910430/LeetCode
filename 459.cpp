#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int split = 2;
        int length = s.length();

        while (split <= length)
        {
            if (length % split == 0)
            {
                int size = length / split;
                bool check = true;
                string token = s.substr(0, size);
                for (int now = 0; now < length; now += size)
                    if (s.substr(now, size) != token)
                    {
                        check = false;
                        break;
                    }
                if (check)
                    return true;
            }
            split++;
        }
        return false;
    }
};