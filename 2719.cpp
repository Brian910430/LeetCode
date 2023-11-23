#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        record.resize(25, vector<vector<long>>(405, vector<long>(2, -1)));
        long lower = solve(0, 0, true, min_sum, max_sum, num1);
        fill(record.begin(), record.end(), vector<vector<long>>(405, vector<long>(2, -1)));
        long upper = solve(0, 0, true, min_sum, max_sum, num2);

        int sum = 0;
        for (auto i : num1)
            sum += (i - '0');
        if (sum >= min_sum and sum <= max_sum)
            lower--;

        return ((upper - lower) + mod) % mod;
    }

private:
    const int mod = 1e9 + 7;
    vector<vector<vector<long>>> record;
    long solve(int index, int sum, bool tight, int min_sum, int max_sum, string &s)
    {
        if (index == s.size())
            return sum >= min_sum and sum <= max_sum;
        if (record[index][sum][tight] != -1)
            return record[index][sum][tight];

        long ans = 0;
        if (tight)
        {
            for (int i = 0; i <= s[index] - '0'; i++)
            {
                if ((s[index] - '0') == i)
                    ans = (ans + solve(index + 1, sum + i, true, min_sum, max_sum, s)) % mod;
                else
                    ans = (ans + solve(index + 1, sum + i, false, min_sum, max_sum, s)) % mod;
            }
        }
        else
        {
            for (int i = 0; i <= 9; i++)
                ans = (ans + solve(index + 1, sum + i, false, min_sum, max_sum, s)) % mod;
        }
        return record[index][sum][tight] = ans;
    }
};

int main()
{
    Solution solution;
    // cout << solution.count("1000000007", "2000000014", 1, 400) << endl;
    cout << solution.count("1", "12", 1, 8) << endl;
    // cout << solution.count("1", "5", 1, 5) << endl;
    return 0;
}