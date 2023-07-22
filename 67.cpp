#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1;
        int j = b.length() - 1;
        char n, m;
        bool carry = false;
        string ans = "";
        while (i >= 0 || j >= 0)
        {
            n = (i >= 0) ? a[i] : '0';
            m = (j >= 0) ? b[j] : '0';
            if (n == '1' && m == '1')
            {
                if (carry)
                {
                    carry = true;
                    ans += '1';
                }
                else
                {
                    carry = true;
                    ans += '0';
                }
            }
            else if (n == '0' && m == '0')
            {
                if (carry)
                {
                    carry = false;
                    ans += '1';
                }
                else
                {
                    carry = false;
                    ans += '0';
                }
            }
            else
            {
                if (carry)
                {
                    carry = true;
                    ans += '0';
                }
                else
                {
                    carry = false;
                    ans += '1';
                }
            }
            i--;
            j--;
        }
        if (carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};