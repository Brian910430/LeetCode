#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> dict1(26, 0);
        vector<int> dict2(26, 0);
        vector<string> ans;

        for (auto c : words[0])
            dict1[c - 'a']++;

        for (int i = 1; i < words.size(); i++)
        {
            for (auto c : words[i])
                dict2[c - 'a']++;
            for (int j = 0; j < 26; j++)
                dict1[j] = min(dict1[j], dict2[j]);
            dict2 = vector<int>(26, 0);
        }

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < dict1[i]; j++)
                ans.push_back(string(1, 'a' + i));
        return ans;
    }
};