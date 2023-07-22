#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> scores = vector<long long>(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int next = (i + questions[i][1] + 1 >= n) ? n : i + questions[i][1] + 1;
            scores[next] = max(scores[next], scores[i] + questions[i][0]);
            scores[i + 1] = max(scores[i + 1], scores[i]);
        }
        return scores[n];
    }
};