/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int c = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        while (l1 && l2)
        {
            if (l1->val + l2->val + c > 9)
            {
                int sum = l1->val + l2->val + c - 10;
                ListNode *newNode = new ListNode(sum);
                dummy->next = newNode;
                dummy = dummy->next;
                c = 1;
            }
            else
            {
                int sum = l1->val + l2->val + c;
                ListNode *newNode = new ListNode(sum);
                dummy->next = newNode;
                dummy = dummy->next;
                c = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            if (l1->val + c > 9)
            {
                int sum = l1->val + c - 10;
                ListNode *newNode = new ListNode(sum);
                dummy->next = newNode;
                dummy = dummy->next;
                c = 1;
            }
            else
            {
                int sum = l1->val + c;
                ListNode *newNode = new ListNode(sum);
                dummy->next = newNode;
                dummy = dummy->next;
                c = 0;
            }
            l1 = l1->next;
        }
        while (l2)
        {
            if (l2->val + c > 9)
            {
                int sum = l2->val + c - 10;
                ListNode *newNode = new ListNode(sum);
                dummy->next = newNode;
                dummy = dummy->next;
                c = 1;
            }
            else
            {
                int sum = l2->val + c;
                ListNode *newNode = new ListNode(sum);
                dummy->next = newNode;
                dummy = dummy->next;
                c = 0;
            }
            l2 = l2->next;
        }

        if (c == 1)
        {
            ListNode *newNode = new ListNode(c);
            dummy->next = newNode;
        }
        return head->next;
    }
};