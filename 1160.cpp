#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int ans = 0;
        vector<int> record(26, 0);
        for (auto i : chars)
            record[i - 'a']++;
        for (auto word : words)
        {
            vector<int> temp = record;
            bool flag = true;
            for (int i = 0; i < word.size(); i++)
            {
                if (temp[word[i] - 'a'] == 0)
                {
                    flag = false;
                    break;
                }
                temp[word[i] - 'a']--;
            }
            if (flag)
                ans += word.size();
        }
        return ans;
    }
};