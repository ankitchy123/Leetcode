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
        ListNode *ans = NULL;
        ListNode *curr;

        while (head)
        {
            curr = head->next;
            head->next = ans;
            ans = head;
            head = curr;
        }

        return ans;
    }
    vector<int> nextLargerNodes(ListNode *head)
    {
        head = reverse(head);
        stack<int> st;
        vector<int> vec;
        while (head)
        {
            while (!st.empty() && st.top() <= head->val)
            {
                st.pop();
            }
            int x = head->val;
            if (st.empty())
            {
                vec.push_back(0);
            }
            else
            {
                vec.push_back(st.top());
            }
            st.push(x);
            head = head->next;
        }
        ::reverse(vec.begin(), vec.end());
        return vec;
    }
};