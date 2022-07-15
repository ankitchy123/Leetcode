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
    int decNum(string str)
    {
        int x = 1;
        int ans = 0;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            ans += x * str[i];
            x *= 2;
        }

        return ans;
    }
    int getDecimalValue(ListNode *head)
    {
        string str = "";

        while (head != NULL)
        {
            str += head->val;
            head = head->next;
        }

        return decNum(str);
    }
};