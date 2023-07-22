#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> record = vector<int>(k, 0);
        return findBest(cookies, 0, record);
    }

private:
    int findBest(vector<int> &cookies, int index, vector<int> &record)
    {
        int best = INT_MAX;
        int n = record.size();
        int temp;

        if (cookies.size() == index)
        {
            best = INT_MIN;
            for (auto i : record)
                best = max(best, i);
            return best;
        }

        for (int i = 0; i < n; i++)
        {
            record[i] += cookies[index];
            temp = findBest(cookies, index + 1, record);
            record[i] -= cookies[index];
            best = min(temp, best);
        }
        return best;
    }
};