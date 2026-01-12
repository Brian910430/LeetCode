#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countPairs(vector<string> &words)
    {
        long long ans = 0;
        map<vector<int>, int> record;

        for (int i = 0; i < words.size(); i++)
        {
            char last = words[i][0];
            vector<int> temp = vector<int>();
            for (int j = 1; j < words[i].length(); j++)
            {
                if (words[i][j] - last < 0)
                    temp.push_back(words[i][j] - last + 26);
                else
                    temp.push_back(words[i][j] - last);
                last = words[i][j];
            }
            record[temp]++;
        }

        for (auto m : record)
        {
            if (m.second > 1)
                ans += (((long long)m.second * (m.second - 1) / 2);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> words = {"fusion", "layout"};
    cout << solution.countPairs(words);
    return 0;
}