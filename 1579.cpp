#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        vector<int> alice = vector<int>();
        vector<int> bob = vector<int>();
        int ans = 0;

        for (int i = 0; i <= n; i++)
        {
            alice.push_back(i);
            bob.push_back(i);
        }

        sort(edges.begin(), edges.end(), compare);
        for (int i = 0; i < edges.size(); i++)
        {
            int a0 = findRoot(alice, edges[i][1]);
            int a1 = findRoot(alice, edges[i][2]);
            int b0 = findRoot(bob, edges[i][1]);
            int b1 = findRoot(bob, edges[i][2]);
            if (edges[i][0] == 3)
            {
                if (a0 == a1 && b0 == b1)
                    ans++;
                else
                {
                    alice[a0] = a1;
                    bob[b0] = b1;
                }
            }
            else if (edges[i][0] == 2)
            {
                if (b0 == b1)
                    ans++;
                else
                    bob[b0] = b1;
            }
            else
            {
                if (a0 == a1)
                    ans++;
                else
                    alice[a0] = a1;
            }
        }
        int ca = 0, cb = 0;
        for (int i = 0; i <= n; i++)
        {
            if (alice[i] == i) ca++;
            if (bob[i] == i) cb++;
        }
        if (ca > 2 || cb > 2)
            return -1;
        return ans;
    }

private:
    int findRoot(vector<int> &parent, int x)
    {
        if (parent[x] != x)
            parent[x] = findRoot(parent, parent[x]);
        return parent[x];
    }

    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == 3 || b[0] == 3)
            return a[0] == 3;
        if (a[0] == 2 || b[0] == 2)
            return a[0] == 2;
        return a[0] == 1;
    }
};