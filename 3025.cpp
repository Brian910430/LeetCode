#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int ans = 0;
        sort(points.begin(), points.end(), cmp);
        for (int i = 0; i < points.size() - 1; i++)
        {
            int y = INT_MAX;
            int yj = points[i][1];
            for (int j = i + 1; j < points.size(); j++)
            {
                int yi = points[j][1];
                if (yi >= yj && y > yi)
                {
                    ans++;
                    y = yi;
                }
            }
        }
        return ans;
    }

private:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
};