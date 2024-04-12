#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        if (num1.length() < num2.length())
            return multiply(num2, num1);

        string ans = "";
        int n = num1.length();
        int m = num2.length();
        for (int i = 0; i < n + m; i++)
            ans += "0";
        for (int i = m; i > 0; i--)
        {
            for (int j = n; j > 0; j--)
            {
                int product = (num1[j - 1] - '0') * (num2[i - 1] - '0');
                int sum = product + ans[i + j - 1] - '0';
                ans[i + j - 1] = sum % 10 + '0';
                ans[i + j - 2] += sum / 10;
            }
        }
        if (ans[0] == '0')
            ans = ans.substr(1);
        return ans;
    }
};