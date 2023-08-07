#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return ans;
        str = "";
        letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backTrack(digits, 0);
        return ans;
    }

private:
    vector<string> ans;
    vector<string> letters;
    string str;
    void backTrack(string digits, int index)
    {
        if (index == digits.length())
        {
            ans.push_back(str);
            return;
        }
        int num = digits[index] - '0' - 2;
        for (int i = 0; i < letters[num].length(); i++)
        {
            str += letters[num][i];
            backTrack(digits, index + 1);
            str.pop_back();
        }
    }
};