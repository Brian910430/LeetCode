#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";

        int len = __gcd(str1.length(), str2.length());
        return str1.substr(0, len);
    }
};

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string ans = "";
        int n = str1.length();
        int m = str2.length();
        for (int i = 1; i <= n && i <= m; i++)
        {
            if (n % i || m % i)
                continue;

            bool flag = true;
            string temp = str1.substr(0, i);
            for (int j = 0; j < n; j += i)
            {
                string slice = str1.substr(j, i);
                if (slice != temp)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int j = 0; j < m; j += i)
                {
                    string slice = str2.substr(j, i);
                    if (slice != temp)
                    {
                        flag = false;
                        break;
                    }
                }
            if (flag)
                ans = temp;
        }
        return ans;
    }
};