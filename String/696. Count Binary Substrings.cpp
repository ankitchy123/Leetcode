class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int curr = 1, prev = 0, ans = 0;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                curr++;
            }
            else
            {
                prev = curr;
                curr = 1;
            }

            if (prev >= curr)
            {
                ans++;
            }
        }

        return ans;
    }
};