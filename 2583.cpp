#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<long long> record;
        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                auto now = q.front();
                q.pop();
                if (now->left)
                    q.push(now->left);
                if (now->right)
                    q.push(now->right);
                sum += now->val;
            }
            record.push_back(sum);
        }
        sort(record.begin(), record.end(), greater<long long>());
        return record.size() >= k ? record[k - 1] : -1;
    }
};