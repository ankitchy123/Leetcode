class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        int l = (s[3] - s[0] + 1) * (s[4] - s[1] + 1);
        int pos = 0;
        vector<string> ans(l);

        for (char c1 = s[0]; c1 <= s[3]; c1++)
        {
            for (char c2 = s[1]; c2 <= s[4]; c2++)
            {
                ans[pos] = c1;
                ans[pos++] += c2;
            }
        }
        return ans;
    }
};