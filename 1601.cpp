#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        ans = 0;
        vector<int> record = vector<int>(n, 0);
        findBest(requests, record, 0, 0);
        return ans;
    }

private:
    int ans;
    void findBest(vector<vector<int>> &requests, vector<int> &record, int index, int score)
    {
        if (index == requests.size())
        {
            for (int i = 0; i < record.size(); i++)
                if (record[i] != 0)
                    return;
            ans = max(ans, score);
            return;
        }
        record[requests[index][0]]--;
        record[requests[index][1]]++;
        findBest(requests, record, index + 1, score + 1);
        record[requests[index][0]]++;
        record[requests[index][1]]--;
        findBest(requests, record, index + 1, score);
    }
};