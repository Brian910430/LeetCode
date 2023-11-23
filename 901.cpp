#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    StockSpanner()
    {
        today = 1;
    }

    int next(int price)
    {
        int ans;
        while (!record.empty() && record.top().first <= price)
            record.pop();
        if (record.empty())
            ans = today;
        else
            ans = today - record.top().second;
        record.push({price, today});
        today++;
        return ans;
    }

private:
    stack<pair<int, int>> record;
    int today;
};