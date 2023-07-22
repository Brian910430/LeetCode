#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int count = 0;
        for (int i = 0; i < word.length(); i++)
            if ('A' <= word[i] && word[i] <= 'Z')
                count++;

        if (count == 0 || count == word.length())
            return true;
        else if (count == 1 && ('A' <= word[0] && word[0] <= 'Z'))
            return true;
        else
            return false;
    }
};