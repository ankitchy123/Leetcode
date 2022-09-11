class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        vector<int> ans(s.size() + 1, 0);
        int l = 0, h = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {
                ans[i] = l++;
            }
            else
            {
                ans[i] = h--;
            }
        }
        ans[s.size()] = l;
        return ans;
    }
};