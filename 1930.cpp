#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_set<string> palindromes;
        int l = s.length();

        for (int i = 0; i < 26; i++)
        {
            int left = 0;
            int right = s.length() - 1;
            while (left < l && s[left] != 'a' + i)
                left++;
            while (right >= 0 && s[right] != 'a' + i)
                right--;
            if (right > left)
                for (int j = left + 1; j < right; j++)
                    palindromes.insert(string() + s[left] + s[j] + s[right]);
        }
        return palindromes.size();
    }
};