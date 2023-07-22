#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int count = 0;
        if (n < 2)
            return 1;
        for (int i = 0; i < n - 1; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int temp = 0;
            unordered_map<double, int> map;
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x2 == x1)
                {
                    map[DBL_MAX]++;
                    temp = max(temp, map[DBL_MAX]);
                }
                else
                {
                    double slope = (double)(y2 - y1) / (x2 - x1);
                    map[slope]++;
                    temp = max(temp, map[slope]);
                }
            }
            count = max(count, temp);
        }
        return count + 1;
    }
};