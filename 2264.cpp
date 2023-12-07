#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int ans = -1;
        int a = num[0] - '0';
        int b = num[0] - '0';
        int c = num[1] - '0';

        for (int i = 2; i < num.size(); i++)
        {
            a = b;
            b = c;
            c = num[i] - '0';
            if (a == b && b == c)
            {
                int temp = a * 100 + b * 10 + c;
                ans = max(ans, temp);
            }
        }
        if (ans == -1)
            return "";
        else if (ans == 0)
            return "000";
        else
            return to_string(ans);
    }
};

int main()
{
    Solution solution;
    string num = "6777133339";
    cout << solution.largestGoodInteger(num) << endl;
    num = "2300019";
    cout << solution.largestGoodInteger(num) << endl;
    num = "42352338";
    cout << solution.largestGoodInteger(num) << endl;
    return 0;
}