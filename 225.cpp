#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    MyStack()
    {
        record = queue<int>();
    }

    void push(int x)
    {
        record.push(x);
    }

    int pop()
    {
        int n = record.size();
        int ans;
        while (n > 1)
        {
            record.push(record.front());
            record.pop();
            n--;
        }
        ans = record.front();
        record.pop();
        return ans;
    }

    int top()
    {
        return record.back();
    }

    bool empty()
    {
        return record.size() == 0;
    }

private:
    queue<int> record;
};