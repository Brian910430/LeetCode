#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        priority_queue<int> heap;
        double maxRate = INT_MIN;
        double ans = INT_MAX;
        int totalQuality = 0;

        for (int i = 0; i < wage.size(); i++)
            pq.push({(double)wage[i] / quality[i], quality[i]});
        for (int i = 0; i < k; i++)
        {
            auto now = pq.top();
            pq.pop();
            maxRate = max(maxRate, now.first);
            totalQuality += now.second;
            heap.push(now.second);
        }
        ans = maxRate * totalQuality;
        for (int i = k; i < wage.size(); i++)
        {
            auto now = pq.top();
            pq.pop();
            maxRate = max(maxRate, now.first);
            totalQuality += now.second;
            totalQuality -= heap.top();
            heap.pop();
            heap.push(now.second);
            ans = min(ans, maxRate * totalQuality);
        }
        return ans;
    }
};