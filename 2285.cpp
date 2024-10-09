#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        priority_queue<int> pq;
        vector<int> record(n, 0);
        long long ans = 0;

        for (auto i : roads)
        {
            record[i[0]]++;
            record[i[1]]++;
        }
        for (int i = 0; i < n; i++)
            pq.push(record[i]);
        for (int i = n; i > 0; i--)
        {
            ans += (long long)i * pq.top();
            pq.pop();
        }
        return ans;
    }
};