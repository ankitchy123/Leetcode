class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (mp.find(t[i]) == mp.end())
            {
                return false;
            }
            else
            {
                mp[t[i]]--;
            }
        }

        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i] > 0)
                return false;
        }

        return true;
    }
};