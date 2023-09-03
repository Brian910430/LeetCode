#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> record;
        int left = candidates - 1;
        int right = costs.size() - candidates;
        long long ans = 0;

        if (costs.size() <= candidates * 2)
            for (int i = 0; i < costs.size(); i++)
                record.push({costs[i], i});
        else
        {
            for (int i = 0; i < candidates; i++)
                record.push({costs[i], i});
            for (int i = 0; i < candidates; i++)
                record.push({costs[right + i], right + i});
        }
        while (k--)
        {
            ans += record.top().first;
            int index = record.top().second;
            record.pop();
            if (left + 1 < right)
            {
                if (index <= left)
                {
                    left++;
                    record.push({costs[left], left});
                }
                else
                {
                    right--;
                    record.push({costs[right], right});
                }
            }
        }
        return ans;
    }
};