#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<ListNode *> list = vector<ListNode *>(100005);
        int n = 1;
        ListNode *now = head;
        while (now != nullptr)
        {
            list[n++] = now;
            now = now->next;
        }
        swap(list[k]->val, list[n - k]->val);
        return head;
    }
};