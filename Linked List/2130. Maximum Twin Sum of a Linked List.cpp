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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode *head)
    {
        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = slow->next;
        slow->next = NULL;

        newHead = reverse(newHead);

        int ans = 0;
        while (head != NULL && newHead != NULL)
        {
            ans = max(ans, head->val + newHead->val);
            head = head->next;
            newHead = newHead->next;
        }
        return ans;
    }
};