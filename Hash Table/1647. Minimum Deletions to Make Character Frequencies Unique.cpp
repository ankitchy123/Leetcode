class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> mp;
        unordered_map<int, int> mp2;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        int ans = 0;

        for (auto i : mp)
        {
            int temp = i.second;
            if (mp2[temp] != 0)
            {
                while (temp > 0 && mp2[temp] != 0)
                {
                    temp--;
                    ans++;
                }
            }
            if (temp > 0)
            {
                mp2[temp]++;
            }
        }
        return ans;
    }
};