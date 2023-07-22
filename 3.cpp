#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = s.length();
        int count = 0, ans = 0, limit = 0;
        map<char, int> Map;
        vector<int> data(length);
        for (int i = 0; i < length; i++)
        {
            if (Map.find(s[i]) != Map.end())
            {
                if (limit < Map[s[i]])
                {
                    count = i - Map[s[i]];
                    limit = Map[s[i]];
                }
                else
                    count = i - limit;
            }
            else
                count++;
            Map[s[i]] = i;
            data[i] = count;
        }
        for (auto a : data)
            if (a > ans)
                ans = a;
        return ans;
    }
};