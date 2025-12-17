#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        if (num1 < num2)
            return countOperations(num2, num1);
        int ans = 0;
        if (num2 == 0)
            return ans;
        ans += num1 / num2;
        num1 = num1 % num2;
        return ans + countOperations(num2, num1);
    }
};