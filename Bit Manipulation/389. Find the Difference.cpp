class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char ans;
        for (int i = 0; i < s.size(); i++)
        {
            ans ^= s[i];
            ans ^= t[i];
        }
        ans ^= t[t.size() - 1];
        return ans;
    }
};