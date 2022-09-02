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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        bool right = true, down = false, left = false, up = false;
        int x = 0, y = m - 1;
        int p = 0, q = n - 1;
        while (head)
        {
            if (right)
            {
                for (int i = p; i <= q; i++)
                {
                    if (!head)
                    {
                        break;
                    }
                    ans[x][i] = head->val;
                    head = head->next;
                }
                x++;
                right = false;
                down = true;
            }
            else if (left)
            {
                for (int i = q; i >= p; i--)
                {
                    if (!head)
                    {
                        break;
                    }
                    ans[y][i] = head->val;
                    head = head->next;
                }
                y--;
                left = false;
                up = true;
            }
            else if (down)
            {
                for (int i = x; i <= y; i++)
                {
                    if (!head)
                    {
                        break;
                    }
                    ans[i][q] = head->val;
                    head = head->next;
                }
                q--;
                left = true;
                down = false;
            }
            else
            {
                for (int i = y; i >= x; i--)
                {
                    if (!head)
                    {
                        break;
                    }
                    ans[i][p] = head->val;
                    head = head->next;
                }
                p++;
                right = true;
                up = false;
            }
        }
        return ans;
    }
};