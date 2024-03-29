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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        ListNode *curr = head;
        while (curr)
        {
            ListNode *prev = dummy;
            while (prev->next && prev->next->val <= curr->val)
            {
                prev = prev->next;
            }

            ListNode *temp = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = temp;
        }
        return dummy->next;
    }
};