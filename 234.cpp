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
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
            return true;
        ListNode *now = head;
        ListNode *next = head;
        ListNode *prev = nullptr;

        while (next->next != nullptr && next->next->next != nullptr)
        {
            now = now->next;
            next = next->next->next;
        }

        prev = now;
        now = prev->next;
        prev->next = nullptr;

        while (now != nullptr)
        {
            next = now->next;
            now->next = prev;
            prev = now;
            now = next;
        }

        while (head != nullptr && prev != nullptr)
        {
            if (head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};