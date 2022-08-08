class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size(), m = s.size();
        int count = 0;
        for (int i = 0, j = 0; i < n && j < m; j++)
        {
            if (s[j] >= g[i])
            {
                count++;
                i++;
            }
        }
        return count;
    }
};