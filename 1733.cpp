#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        vector<unordered_set<int>> alreadyKnows = vector<unordered_set<int>>(languages.size() + 1, unordered_set<int>());
        unordered_set<int> needFix = unordered_set<int>();
        int ans = INT_MAX;
        for (int i = 0; i < languages.size(); i++)
            for (auto l : languages[i])
                alreadyKnows[i + 1].insert(l);
        for (int i = 0; i < friendships.size(); i++)
        {
            int u = friendships[i][0];
            int v = friendships[i][1];
            for (auto l : languages[u - 1])
                if (alreadyKnows[v].count(l))
                    goto next;
            needFix.insert(u);
            needFix.insert(v);
        next:;
        }
        for (int i = 1; i <= n; i++)
        {
            int count = 0;
            for (auto p : needFix)
                if (alreadyKnows[p].count(i))
                    count++;
            ans = min(static_cast<int>(needFix.size()) - count, ans);
        }
        return ans;
    }
};