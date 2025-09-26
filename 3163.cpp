#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compressedString(string word)
    {
        string ans = "";
        char now = word[0];
        int count = 0;

        for (int i = 0; i < word.length(); i++)
        {
            if (now == word[i] && count < 9)
                count++;
            else
            {
                ans.push_back('0' + count);
                ans.push_back(now);
                now = word[i];
                count = 1;
            }
        }
        ans.push_back('0' + count);
        ans.push_back(now);
        return ans;
    }
};