class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int start = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            if (mp[s[i]] > 1)
            {
                while (start < s.length() && mp[s[i]] > 1)
                {
                    mp[s[start]]--;
                    start++;
                }
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};