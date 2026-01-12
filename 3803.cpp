#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int residuePrefixes(string s)
    {
        unordered_set<char> record;
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            record.insert(s[i]);
            ans += ((i + 1) % 3 == record.size());
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.residuePrefixes("abc") << endl;
    return 0;
}