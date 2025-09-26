#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;
        double ans = 0;
        auto profit = [](int pass, int total)
        {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        for (int i = 0; i < classes.size(); i++)
            pq.push({profit(classes[i][0], classes[i][1]), i});

        while (extraStudents--)
        {
            auto prof = pq.top().first;
            auto index = pq.top().second;
            pq.pop();
            classes[index][0]++, classes[index][1]++;
            pq.push({profit(classes[index][0], classes[index][1]), index});
        }

        for (int i = 0; i < classes.size(); i++)
            ans += (double)classes[i][0] / classes[i][1];
        return ans / classes.size();
    }
};