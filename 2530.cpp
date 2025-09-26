#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, less<int>> pq;
        long long ans = 0;

        for (auto i : nums)
            pq.push(i);
        while (k--)
        {
            int now = pq.top();
            ans += now;
            if (now % 3)
                now += 3;
            now /= 3;
            pq.pop();
            pq.push(now);
        }
        return ans;
    }
};