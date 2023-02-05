class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int s_len = s.length();
        int p_len = p.length();

        if (s.size() < p.size())
        {
            return {};
        }

        vector<int> vec1(26, 0), vec2(26, 0);

        for (int i = 0; i < p.size(); i++)
        {
            vec1[p[i] - 'a']++;
            vec2[s[i] - 'a']++;
        }

        vector<int> ans;
        for (int i = 0; i < s.size() - p.size(); i++)
        {
            if (vec1 == vec2)
            {
                ans.push_back(i);
            }
            vec2[s[i + p.size()] - 'a']++;
            vec2[s[i] - 'a']--;
        }
        if (vec1 == vec2)
        {
            ans.push_back(s.size() - p.size());
        }
        return ans;
    }
};