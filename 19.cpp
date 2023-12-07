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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> record = vector<ListNode *>();
        ListNode *now = head;
        while (now != nullptr)
        {
            record.push_back(now);
            now = now->next;
        }
        if (n == record.size())
            return record.size() == 1 ? nullptr : record[1];
        else if (n == 1)
        {
            record[record.size() - 2]->next = nullptr;
            return head;
        }
        else
        {
            record[record.size() - n - 1]->next = record[record.size() - n + 1];
            return head;
        }
    }
};