#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int ans = 0;

        for (int i = 0; i < logs.size(); i++)
        {
            if (logs[i] == "../")
                ans = ans > 0 ? ans - 1 : 0;
            else if (logs[i] == "./")
                ;
            else
                ans++;
        }
        return ans;
    }
};