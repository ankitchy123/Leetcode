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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *temp1 = head, *temp2 = head->next, *prev = NULL;
        while (temp2)
        {
            if (temp1->val == temp2->val)
            {
                while (temp2 && temp1->val == temp2->val)
                {
                    temp2 = temp2->next;
                }

                if (prev == NULL)
                {
                    temp1 = temp2;
                    head = temp2;
                }
                else
                {
                    prev->next = temp2;
                    temp1 = temp2;
                }
            }
            else
            {
                prev = temp1;
                temp1 = temp1->next;
            }

            if (temp2 != NULL)
            {
                temp2 = temp2->next;
            }
        }
        return head;
    }
};