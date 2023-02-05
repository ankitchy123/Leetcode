class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_set<int> st;
        for (int i = 0; i < banned.size(); i++)
        {
            if (banned[i] <= n)
            {
                st.insert(banned[i]);
            }
        }

        int count = 0, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (st.find(i) == st.end())
            {
                if (sum + i > maxSum)
                {
                    return count;
                }
                sum += i;
                count++;
            }
        }
        return count;
    }
};