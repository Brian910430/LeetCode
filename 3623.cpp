#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        unordered_map<int, int> yCount;
        vector<long long> combCount;
        long long prefixSum = 0;
        long long ans = 0;

        for (auto point : points)
            yCount[point[1]]++;
        for (auto &[y, count] : yCount)
            if (count >= 2)
                combCount.push_back(combination(count, 2));
        prefixSum = combCount.size() > 0 ? combCount[0] : 0;
        for (int i = 1; i < combCount.size(); i++)
        {
            ans = (ans + combCount[i] * prefixSum) % (int)(1e9 + 7);
            prefixSum = (prefixSum + combCount[i]) % (int)(1e9 + 7);
        }
        return (int)ans;
    }

private:
    int combination(int n, int r)
    {
        long long res = 1;
        for (int i = 0; i < r; i++)
            res = res * n-- / (i + 1);
        return (int)res;
    }
};