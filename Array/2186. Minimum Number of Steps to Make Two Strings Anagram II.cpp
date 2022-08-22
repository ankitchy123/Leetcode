class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> vec(26, 0);
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0 && j >= 0)
        {
            vec[s[i] - 'a']++;
            vec[t[j] - 'a']--;
            i--;
            j--;
        }
        while (i >= 0)
        {
            vec[s[i] - 'a']++;
            i--;
        }
        while (j >= 0)
        {
            vec[t[j] - 'a']--;
            j--;
        }

        int ans = 0;
        for (int k = 0; k < 26; k++)
        {
            ans += abs(vec[k]);
        }
        return ans;
    }
};