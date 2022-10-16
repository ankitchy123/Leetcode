class Solution
{
public:
    string sortString(string s)
    {
        vector<int> vec(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            vec[s[i] - 'a']++;
        }

        string ans = "";
        while (ans.size() < s.size())
        {
            for (int i = 0; i < 26; i++)
            {
                if (vec[i] > 0)
                {
                    ans += i + 'a';
                    vec[i]--;
                }
            }
            for (int i = 25; i >= 0; i--)
            {
                if (vec[i] > 0)
                {
                    ans += i + 'a';
                    vec[i]--;
                }
            }
        }

        return ans;
    }
};