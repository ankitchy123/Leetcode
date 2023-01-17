class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int count = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                count++;
            }
            else
            {
                ans = min(ans + 1, count);
            }
        }
        return ans;
    }
};