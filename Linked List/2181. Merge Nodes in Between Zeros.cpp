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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *temp = head, *t2 = head;
        int sum = 0;
        while (temp)
        {
            sum += temp->val;
            temp = temp->next;
            if (temp && temp->val == 0)
            {
                ListNode *temp2 = new ListNode(sum);
                t2->next = temp2;
                t2 = t2->next;
                temp = temp->next;
                sum = 0;
            }
        }

        return head->next;
    }
};