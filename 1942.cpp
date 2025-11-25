#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        unordered_map<int, int> friendIndex;

        int n = times.size();
        for (int i = 0; i < n; i++)
        {
            availableChairs.push(i);
            friendIndex[times[i][0]] = i;
        }
        sort(times.begin(), times.end());
        for (int i = 0; i < n; i++)
        {
            while (occupiedChairs.size() > 0 && occupiedChairs.top().first <= times[i][0])
            {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }
            if (friendIndex[times[i][0]] == targetFriend)
                return availableChairs.top();
            occupiedChairs.push({times[i][1], availableChairs.top()});
            availableChairs.pop();
        }
        return -1;
    }
};