#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        string ans = "";
        int n = 0;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while (pq.size())
        {
            auto temp = pq.top();
            pq.pop();
            n = ans.length();
            if (n >= 2 && ans[n - 1] == ans[n - 2] && ans[n - 1] == temp.second)
            {
                if (pq.empty()) break;
                auto temp2 = pq.top();
                pq.pop();
                ans.push_back(temp2.second);
                temp2.first--;
                if (temp2.first) pq.push(temp2);
                if (temp.first) pq.push(temp);
            }
            else
            {
                ans.push_back(temp.second);
                temp.first--;
                if (temp.first) pq.push(temp);
            }
        }
        return ans;
    }
};