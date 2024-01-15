#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int n = s.length();
        int left = 0;
        int right = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for (int i = 0; i < n / 2; i++)
        {
            left += vowels.count(s[i]);
            right += vowels.count(s[n - 1 - i]);
        }
        return left == right;
    }
};