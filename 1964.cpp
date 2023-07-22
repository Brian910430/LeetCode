#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> ans = vector<int>();
        vector<int> record = vector<int>();

        for (int i = 0; i < n; i++)
        {
            int index = upper_bound(record.begin(), record.end(), obstacles[i]) - record.begin();
            if (index == record.size())
                record.push_back(obstacles[i]);
            else
                record[index] = obstacles[i];
            ans.push_back(index + 1);
        }
        return ans;
    }
};