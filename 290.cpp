#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        map<char, string> map1;
        map<string, char> map2;
        int start = 0, end = 0, count = 0;
        int length = pattern.length();
        s += ' ';

        for (int i = 0; i < s.length(); i++)
            if (s[i] == ' ')
                count++;
        if (count != length)
            return false;

        for (int i = 0; i < length; i++)
        {
            while (s[end] != ' ')
                end++;
            string word = s.substr(start, end - start);
            if (map1.find(pattern[i]) != map1.end() || map2.find(word) != map2.end())
            {
                if (map1[pattern[i]] != word || map2[word] != pattern[i])
                    return false;
            }
            else
            {
                map1[pattern[i]] = word;
                map2[word] = pattern[i];
            }
            start = end + 1;
            end = start;
        }
        return true;
    }
};