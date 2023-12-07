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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        ListNode *ans = new ListNode();
        ListNode *now = ans;

        for (auto i : lists)
            if (i != nullptr)
                pq.push({i->val, i});
        while (pq.size())
        {
            auto temp = pq.top();
            pq.pop();
            now->next = temp.second;
            if (temp.second->next != nullptr)
                pq.push({temp.second->next->val, temp.second->next});
            now = now->next;
        }
        return ans->next;
    }
};