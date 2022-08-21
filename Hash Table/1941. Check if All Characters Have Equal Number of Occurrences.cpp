class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        int count = mp[s[0]];
        for (int i = 1; i < s.size(); i++)
        {
            if (mp[s[i]] != count)
            {
                return false;
            }
        }
        return true;
    }
};