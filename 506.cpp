#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<string> ans = vector<string>(score.size());
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < score.size(); i++)
            pq.push({score[i], i});
        for (int i = 0; i < score.size(); i++)
        {
            if (i == 0)
                ans[pq.top().second] = "Gold Medal";
            else if (i == 1)
                ans[pq.top().second] = "Silver Medal";
            else if (i == 2)
                ans[pq.top().second] = "Bronze Medal";
            else
                ans[pq.top().second] = to_string(i + 1);
            pq.pop();
        }
        return ans;
    }
};