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
    ListNode *doubleIt(ListNode *head)
    {
        head = new ListNode(0, head);
        doubleHelper(head);
        return head->val == 0 ? head->next : head;
    }

private:
    int doubleHelper(ListNode *head)
    {
        if (head == nullptr)
            return 0;
        int sum = doubleHelper(head->next) + head->val * 2;
        head->val = sum % 10;
        return sum / 10;
    }
};