#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;
        int n = word1.size();
        vector<int> str1 = vector<int>(26, 0);
        vector<int> str2 = vector<int>(26, 0);

        for (int i = 0; i < n; i++)
        {
            str1[word1[i] - 'a']++;
            str2[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
            if (str1[i] == 0 && str2[i] != 0 || str1[i] != 0 && str2[i] == 0)
                return false;
        sort(str1.begin(), str1.end(), greater<int>());
        sort(str2.begin(), str2.end(), greater<int>());
        for (int i = 0; i < 26; i++)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
};