#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        priority_queue<pair<char, int>> pq;
        string numStr = to_string(num);
        for (int i = 0; i < numStr.length(); i++)
            pq.push({numStr[i], i});
        for (int i = 0; i < numStr.length(); i++)
        {
            if (pq.top().second == i)
                pq.pop();
            else if (pq.top().first == numStr[i] && pq.top().second != i)
            {
                auto temp = pq.top();
                pq.pop();
                if (pq.empty())
                    break;
                pq.pop();
                pq.push(temp);
            }
            else if (pq.top().first > numStr[i] && pq.top().second > i)
            {
                swap(numStr[i], numStr[pq.top().second]);
                return stoi(numStr);
            }
        }
        return num;
    }
};