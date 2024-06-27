#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int index = 0;
        vector<pair<int, int>> pq1;
        priority_queue<int, vector<int>, less<int>> pq2;

        for (int i = 0; i < profits.size(); i++)
            pq1.push_back({capital[i], profits[i]});
        sort(pq1.begin(), pq1.end(), less<pair<int, int>>());
        while (k--)
        {
            while (index < pq1.size() && w >= pq1[index].first)
            {
                pq2.push(pq1[index].second);
                index++;
            }
            if (pq2.empty())
                break;
            w += pq2.top();
            pq2.pop();
        }
        return w;
    }
};