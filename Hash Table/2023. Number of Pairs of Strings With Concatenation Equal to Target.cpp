class Solution
{
public:
    int numOfPairs(vector<string> &nums, string target)
    {
        map<string, int> mp;
        int ans = 0;
        for (auto x : nums)
        {
            mp[x]++;
        }
        string s1 = "";
        for (int i = 0; i < target.size(); i++)
        {
            s1 += target[i];
            string s2 = target.substr(i + 1);
            if (mp.find(s1) != mp.end() && mp.find(s2) != mp.end())
            {
                if (s1 == s2)
                {
                    ans += mp[s1] * (mp[s2] - 1);
                }
                else
                {
                    ans += mp[s1] * mp[s2];
                }
            }
        }
        return ans;
    }
};