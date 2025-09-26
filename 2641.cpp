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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        int index = 0;
        queue<pair<TreeNode *, int>> q;
        vector<int> record;
        q.push({root, 0});
        while (q.size())
        {
            int n = q.size();
            int sum = 0;
            while (n--)
            {
                TreeNode *now = q.front().first;
                q.pop();
                if (now->left)
                    q.push({now->left, 0});
                if (now->right)
                    q.push({now->right, 0});
                sum += now->val;
            }
            record.push_back(sum);
        }

        q.push({root, 0});
        while (q.size())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *now = q.front().first;
                int val = q.front().second;
                q.pop();
                if (now->left && now->right)
                {
                    q.push({now->left, now->right->val});
                    q.push({now->right, now->left->val});
                }
                else if (now->left)
                    q.push({now->left, 0});
                else if (now->right)
                    q.push({now->right, 0});
                now->val = record[index] - val - now->val;
            }
            index++;
        }
        return root;
    }
};