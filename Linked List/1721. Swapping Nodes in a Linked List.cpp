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
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<ListNode *> vec;
        ListNode *temp = head;

        while (temp)
        {
            vec.push_back(temp);
            temp = temp->next;
        }

        ListNode *n2 = vec[vec.size() - k], *n1 = vec[k - 1];

        swap(n1->val, n2->val);
        return head;
    }
};