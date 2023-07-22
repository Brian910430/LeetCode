#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int ans = 0;
        int n = arr.size() + 1;
        arr.insert(arr.begin(), 0);
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];

        for (int i = 1; i < n; i += 2)
            for (int j = 0; j < n; j++)
                if (j + i < n)
                    ans += (arr[j + i] - arr[j]);
        return ans;
    }
};