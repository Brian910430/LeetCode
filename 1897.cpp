#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        vector<int> dict(26, 0);
        for (int i = 0; i < n; i++)
            for (auto c : words[i])
                dict[c - 'a']++;
        for (auto i : dict)
            if (i % n != 0)
                return false;
        return true;
    }
};