#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int rank = 0;
        int last = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
            pq.push({arr[i], i});
        while (pq.size())
        {
            pq.top().first == last ? arr[pq.top().second] = rank : arr[pq.top().second] = ++rank;
            last = pq.top().first;
            pq.pop();
        }
        return arr;
    }
};