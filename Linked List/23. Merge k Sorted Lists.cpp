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
    ListNode *mergeList(ListNode *list1, ListNode *list2)
    {
        if (list2 == NULL)
        {
            return list1;
        }
        ListNode *head = NULL;
        if (list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }
        ListNode *newList = head;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                newList->next = list2;
                list2 = list2->next;
            }
            else
            {
                newList->next = list1;
                list1 = list1->next;
            }
            newList = newList->next;
        }

        if (list1)
        {
            newList->next = list1;
        }
        else
        {
            newList->next = list2;
        }
        return head;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return NULL;
        }
        int n = lists.size();

        for (int i = 1; i < n; i++)
        {
            if (lists[i] == NULL)
            {
                continue;
            }
            ListNode *temp = mergeList(lists[i], lists[0]);
            lists[0] = temp;
        }

        return lists[0];
    }
};