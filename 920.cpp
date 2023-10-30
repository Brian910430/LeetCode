#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        s.clear();
        backTrack(n, goal, k, 0);
        return ans;
    }
};

int main()
{
    Solution solution;
    return 0;
}