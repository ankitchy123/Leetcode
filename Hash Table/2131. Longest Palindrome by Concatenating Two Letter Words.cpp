class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> mp;
        for (const string &word : words)
        {
            mp[word]++;
        }
        int ans = 0;
        bool flag = false;
        for (auto i : mp)
        {
            string s = i.first;
            string t = s;
            reverse(s.begin(), s.end());
            if (s == t)
            {
                ans += i.second / 2;
                if (i.second % 2)
                {
                    flag = true;
                }
            }
            else if (mp.count(s))
            {
                ans += min(i.second, mp[s]), mp.erase(s);
            }
        }
        ans *= 4;
        if (flag)
        {
            ans += 2;
        }
        return ans;
    }
};