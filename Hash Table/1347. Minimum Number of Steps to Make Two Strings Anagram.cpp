class Solution
{
public:
    int minSteps(string s, string t)
    {
        map<char, int> mp;
        int i = 0;
        while (i < s.size())
        {
            mp[s[i]]++;
            mp[t[i]]--;
            i++;
        }

        int ans = 0;
        for (auto i : mp)
        {
            if (i.second > 0)
            {
                ans += i.second;
            }
        }
        return ans;
    }
};