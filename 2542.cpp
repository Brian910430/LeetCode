#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        long long tempSum = 0;
        long long ans = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        for (int i = 0; i < n; i++)
            pq1.push({nums2[i], nums1[i]});

        for (int i = 0; i < n; i++)
        {
            tempSum += pq1.top().second;
            pq2.push(pq1.top().second);
            if (i >= k)
            {
                tempSum -= pq2.top();
                pq2.pop();
            }
            if (i >= k - 1)
                ans = max(ans, (long long)tempSum * pq1.top().first);
            pq1.pop();
        }
        return ans;
    }
};