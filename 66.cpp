#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        digits[n]++;
        while (digits[n] == 10)
        {
            digits[n] = 0;
            if (n)
                digits[--n]++;
            else
                digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};