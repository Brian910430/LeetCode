#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> pq;
        int ans = 0;

        for (int i = 0; i < difficulty.size(); i++)
            pq.push_back({profit[i], difficulty[i]});
        sort(pq.begin(), pq.end(), greater<pair<int, int>>());
        sort(worker.begin(), worker.end(), greater<int>());

        for (int i = 0, j = 0; i < worker.size(); i++)
            for (; j < pq.size(); j++)
                if (worker[i] >= pq[j].second)
                {
                    ans += pq[j].first;
                    break;
                }
        return ans;
    }
};