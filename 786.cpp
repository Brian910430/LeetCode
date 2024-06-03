#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        for(int i=0;i<arr.size();i++)
            pq.push({(double)arr[i]/arr[arr.size()-1], {i, arr.size()-1}});
        while(k>1)
        {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            if(j>i)
                pq.push({(double)arr[i]/arr[j-1], {i, j-1}});
            k--;
        }
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};