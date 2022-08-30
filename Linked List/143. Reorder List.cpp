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
    void reorderList(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;
        ListNode *curr = head;

        if (!head)
        {
            return;
        }

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        while (slow)
        {
            st.push(slow);
            slow = slow->next;
        }

        while (!st.empty())
        {
            ListNode *ele = st.top();
            st.pop();
            if (curr == ele)
            {
                break;
            }
            prev = curr->next;
            curr->next = ele;
            ele->next = prev;
            curr = prev;
        }
        curr->next = NULL;
    }
};