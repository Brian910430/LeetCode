#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int max = 0;
        stack<int> record;
        for (auto c : s)
        {
            if (c == '(')
                record.push(0);
            else
            {
                if (record.empty())
                    continue;
                if (record.top() == 0)
                {
                    record.pop();
                    if (record.empty() || record.top() < 2)
                        record.push(2);
                    else
                        record.top() += 2;
                }
                else if (record.top() > 1)
                {
                    int now = record.top();
                    record.pop();
                    if (record.empty() || record.top() == 1)
                    {
                        record.push(now);
                        record.push(1);
                    }
                    else if (record.top() == 0)
                    {
                        record.pop();
                        if (record.empty() || record.top() < 2)
                            record.push(now + 2);
                        else
                            record.top() += (now + 2);
                    }
                }
                else
                    record.push(1);
            }
        }
        while (!record.empty())
        {
            if (record.top() > max && record.top() != 1)
                max = record.top();
            record.pop();
        }
        return max;
    }
};