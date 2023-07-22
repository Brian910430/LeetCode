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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *prev = nullptr;
        head = head->next;

        while (first != nullptr && first->next != nullptr)
        {
            second = first->next;
            ListNode *temp = second->next;
            second->next = first;
            first->next = temp;
            if (prev != nullptr)
                prev->next = second;
            prev = first;
            first = first->next;
        }
        return head;
    }
};