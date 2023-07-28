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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *prev = head;
        ListNode *now = head->next;

        while (now != nullptr)
        {
            ListNode *next = now->next;
            now->next = prev;
            prev = now;
            now = next;
        }
        head->next = nullptr;
        return prev;
    }
};