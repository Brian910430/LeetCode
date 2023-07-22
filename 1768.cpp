#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans = "";
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.length())
        {
            ans += word1[i++];
            ans += word2[j++];
        }
        if (i == word1.length())
            ans += word2.substr(j, word2.length() - j);
        if (j == word2.length())
            ans += word1.substr(i, word1.length() - i);
        return ans;
    }
};