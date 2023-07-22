#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (!points.size())
            return 0;

        sort(points.begin(), points.end());
        int count = 1;
        int lastpoint = points[0][1];
        for (auto point : points)
        {
            if (point[0] > lastpoint)
            {
                count++;
                lastpoint = point[1];
            }
            lastpoint = min(lastpoint, point[1]);
        }
        return count;
    }
};