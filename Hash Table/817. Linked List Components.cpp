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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        int ans = 0;
        while (head)
        {
            if (st.find(head->val) != st.end())
            {
                ans++;
            }
            while (head && st.find(head->val) != st.end())
            {
                head = head->next;
            }
            if (head)
            {
                head = head->next;
            }
        }
        return ans;
    }
};