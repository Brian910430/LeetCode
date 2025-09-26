#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), compare);

        for (int i = 0; i < intervals.size(); i++)
        {
            if (pq.size() && intervals[i][0] > pq.top())
                pq.pop();
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }

private:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
};