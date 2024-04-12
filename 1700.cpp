#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        int ones = 0;
        int zeros = 0;

        for (int i = 0; i < n; i++)
        {
            if (students[i] == 1)
                ones++;
            else
                zeros++;
        }
        for (int i = 0; i < n; i++)
        {
            if (sandwiches[i] == 1)
                ones--;
            else
                zeros--;
            if (ones < 0 || zeros < 0)
                return n - i;
        }
        return 0;
    }
};