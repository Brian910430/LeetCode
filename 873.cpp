#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int ans = 0;
        int n = arr.size();
        vector<vector<int>> record = vector<vector<int>>(n, vector<int>(n, 0));

        for (int i = 2; i < n; i++)
        {
            int l = 0;
            int r = i - 1;
            while (l < r)
            {
                int sum = arr[l] + arr[r];
                if (arr[i] < sum)
                    r--;
                else if (arr[i] > sum)
                    l++;
                else
                {
                    record[r][i] = record[l][r] + 1;
                    ans = max(record[r][i], ans);
                    r--;
                    l++;
                }
            }
        }
        return ans == 0 ? 0 : ans + 2;
    }
};