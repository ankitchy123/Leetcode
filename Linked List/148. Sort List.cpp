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
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *temp = head;
        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        return slow;
    }

    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode dummyHead(0);
        ListNode *ptr = &dummyHead;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                ptr->next = list1;
                list1 = list1->next;
            }
            else
            {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if (list1)
        {
            ptr->next = list1;
        }
        else
        {
            ptr->next = list2;
        }

        return dummyHead.next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }
};