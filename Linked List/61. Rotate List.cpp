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
    int length(ListNode *head)
    {
        int ans = 0;
        while (head)
        {
            ans++;
            head = head->next;
        }
        return ans;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        int l = length(head);
        if (k == 0 || !head)
        {
            return head;
        }

        k %= l;

        if (k == 0)
        {
            return head;
        }

        int count = 1;
        ListNode *temp = head;

        while (count != l - k && temp)
        {
            temp = temp->next;
            count++;
        }

        ListNode *temp2 = temp->next;
        temp->next = NULL;
        ListNode *newHead = temp2;

        while (temp2->next)
        {
            temp2 = temp2->next;
        }
        temp2->next = head;
        return newHead;
    }
};