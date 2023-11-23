#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findValidSplit(vector<int> &nums)
    {
        unordered_map<int, int> record;
        vector<int> line(nums.size() + 5, 0);
        for (int i = 0; i < nums.size(); ++i)
            for (int j : primeFactor(nums[i]))
            {
                if (record.count(j) == 0)
                    record[j] = i;
                line[record[j]]++;
                line[i]--;
            }
        partial_sum(line.begin(), line.end(), line.begin());
        int res = find(line.begin(), line.end(), 0) - line.begin();
        return res < nums.size() - 1 ? res : -1;
    }

private:
    set<int> primeFactor(int n)
    {
        set<int> ans;
        for (int i = 2; i <= n; i++)
        {
            if (n / i < i)
            {
                ans.insert(n);
                break;
            }
            while (1)
                if (n % i == 0)
                {
                    n /= i;
                    ans.insert(i);
                }
                else
                    break;
        }
        return ans;
    }
};