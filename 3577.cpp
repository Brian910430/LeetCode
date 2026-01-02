#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPermutations(vector<int> &complexity)
    {
        int root = complexity[0];
        sort(complexity.begin(), complexity.end());
        if (root != complexity[0] || root == complexity[1])
            return 0;
        return (int)factorial(complexity.size() - 1);
    }

private:
    long long factorial(int n)
    {
        if (n == 1)
            return 1;
        return (factorial(n - 1) * n) % (long long)(1e9 + 7);
    }
};