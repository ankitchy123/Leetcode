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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> vec;
        ListNode *prev = head;
        head = head->next;

        int i = 0;
        while (head->next != NULL)
        {
            i++;
            if (head->val > prev->val && head->val > head->next->val)
            {
                vec.push_back(i);
            }
            else if (head->val < prev->val && head->val < head->next->val)
            {
                vec.push_back(i);
            }
            prev = head;
            head = head->next;
        }
        if (vec.size() == 0 || vec.size() == 1)
        {
            return {-1, -1};
        }
        int m1 = INT_MAX, m2 = vec[vec.size() - 1] - vec[0];
        for (int i = 0; i < vec.size() - 1; i++)
        {
            int x = abs(vec[i] - vec[i + 1]);

            if (x < m1)
            {
                m1 = x;
            }
        }

        return {m1, m2};
    }
};