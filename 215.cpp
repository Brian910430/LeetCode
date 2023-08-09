#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> record(nums.begin(), nums.end());
        int n = record.size();
        for (int i = 0; i < k - 1; i++)
            record.pop();
        return record.top();
    }
};