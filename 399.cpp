#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> maps;
        vector<double> ans = vector<double>();
        for (int i = 0; i < equations.size(); i++)
        {
            maps[equations[i][0]][equations[i][1]] = values[i];
            maps[equations[i][1]][equations[i][0]] = 1 / values[i];
        }

        for (int i = 0; i < queries.size(); i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];
            unordered_map<string, bool> visited;
            queue<pair<string, string>> q;
            if (maps.find(start) == maps.end())
            {
                ans.push_back(-1);
                continue;
            }

            maps[start][start] = 1;
            q.push({"A", start});
            while (q.size())
            {
                auto now = q.front();
                q.pop();
                visited[now.second] = true;
                for (auto item : maps[now.second])
                {
                    if (visited[item.first])
                        continue;
                    q.push({now.second, item.first});
                    maps[start][item.first] = maps[start][now.second] * item.second;
                }
                if (now.second == end)
                {
                    ans.push_back(maps[start][end]);
                    break;
                }
            }
            if (ans.size() == i)
                ans.push_back(-1);
        }
        return ans;
    }
};