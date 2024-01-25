#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        if (jobDifficulty.size() < d)
            return -1;
        int n = jobDifficulty.size();
        record = vector<vector<int>>(n + 5, vector<int>(d + 5, -1));
        return backTrack(jobDifficulty, d, 0, 0);
    }

private:
    vector<vector<int>> record;
    int backTrack(vector<int> &jobDifficulty, int d, int index, int day)
    {
        if (record[index][day] != -1)
            return record[index][day];
        if (day == d || index == jobDifficulty.size())
            return record[index][day] = INT_MAX;
        if (day == d - 1)
        {
            int ans = INT_MIN;
            for (int i = index; i < jobDifficulty.size(); i++)
                ans = max(ans, jobDifficulty[i]);
            return record[index][day] = ans;
        }

        int n = jobDifficulty.size();
        int ans = INT_MAX;
        int maxDifficulty = INT_MIN;
        for (int i = index; i < n - d + day + 1; i++)
        {
            maxDifficulty = max(maxDifficulty, jobDifficulty[i]);
            int temp = backTrack(jobDifficulty, d, i + 1, day + 1);
            ans = min(ans, maxDifficulty + (temp == INT_MAX ? 0 : temp));
        }
        return record[index][day] = ans;
    }
};