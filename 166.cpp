#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string ans = "";
        if ((ll)numerator * denominator < 0)
            ans += '-';

        ll n = abs((ll)numerator);
        ll d = abs((ll)denominator);
        ll remainder = n % d;
        ans += to_string(n / d);
        if (remainder == 0)
            return ans;

        unordered_map<ll, int> record;
        ans += ".";
        while (remainder != 0)
        {
            if (record.count(remainder))
            {
                ans.insert(record[remainder], "(");
                ans += ")";
                break;
            }
            record[remainder] = ans.length();
            ans += '0' + (remainder * 10) / d;
            remainder = (remainder * 10) % d;
        }
        return ans;
    }
};