#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> allJobs(n);
        vector<int> record(n + 5, 0);

        for (int i = 0; i < n; i++)
            allJobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(allJobs.begin(), allJobs.end());

        for (int i = n - 1; i >= 0; i--)
        {
            int notTake = record[i + 1];
            vector<int> v = {allJobs[i][1], 0, 0};
            int nextIdx = lower_bound(allJobs.begin(), allJobs.end(), v) - allJobs.begin();
            int take = allJobs[i][2] + record[nextIdx];
            record[i] = max(take, notTake);
        }
        return record[0];
    }
};