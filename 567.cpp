#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length()) return false;

        vector<int> s1_map = vector<int>(26, 0);
        vector<int> record = vector<int>(26, 0);
        for (int i = 0; i < s1.length(); i++)
            s1_map[s1[i] - 'a']++;
        for (int i = 0; i < s1.length() - 1; i++)
            record[s2[i] - 'a']++;

        if (s1_map == record) return true;
        for (int left = 0, right = left + s1.length() - 1; right < s2.length(); left++, right++)
        {
            record[s2[right] - 'a']++;
            if (s1_map == record)
                return true;
            record[s2[left] - 'a']--;
        }
        return false;
    }
};