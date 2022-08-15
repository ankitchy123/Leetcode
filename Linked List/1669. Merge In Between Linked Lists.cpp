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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *head = list1;

        for (int i = 1; i < a; i++)
        {
            list1 = list1->next;
        }
        ListNode *temp = list1->next;
        list1->next = list2;

        while (list1->next)
        {
            list1 = list1->next;
        }

        for (int i = a; i < b; i++)
        {
            temp = temp->next;
        }

        list1->next = temp->next;
        return head;
    }
};