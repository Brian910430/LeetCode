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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *now = root;
        TreeNode *prev = root;
        while (now != nullptr)
        {
            if (now->val < key)
            {
                prev = now;
                now = now->right;
            }
            else if (now->val > key)
            {
                prev = now;
                now = now->left;
            }
            else
                break;
        }

        if (now == nullptr)
            return root;
        else if (now->left == nullptr && now->right == nullptr)
        {
            if (now == root)
                return nullptr;
            if (prev->left == now)
                prev->left = nullptr;
            else
                prev->right = nullptr;
            return root;
        }
        else if (now->right != nullptr)
        {
            TreeNode *node = now->right;
            TreeNode *nextNode = now->right;
            while (nextNode->left != nullptr)
            {
                node = nextNode;
                nextNode = nextNode->left;
            }
            if (node == nextNode)
            {
                now->val = node->val;
                now->right = node->right;
            }
            else
            {
                now->val = nextNode->val;
                node->left = nextNode->right;
            }
        }
        else
        {
            TreeNode *node = now->left;
            TreeNode *nextNode = now->left;
            while (nextNode->right != nullptr)
            {
                node = nextNode;
                nextNode = nextNode->right;
            }
            if (node == nextNode)
            {
                now->val = node->val;
                now->left = node->left;
            }
            else
            {
                now->val = nextNode->val;
                node->right = nextNode->left;
            }
        }
        return root;
    }
};