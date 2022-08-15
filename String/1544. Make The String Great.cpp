class Solution
{
public:
    string makeGood(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ans.back() + 32 || s[i] + 32 == ans.back())
            {
                ans.pop_back();
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};