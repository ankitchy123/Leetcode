class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        string ans;
        if (k == 1)
        {
            int n = s.size();
            ans = s;
            s += s;
            for (int i = 1; i < n; i++)
            {
                ans = min(ans, s.substr(i, n));
            }
        }
        else
        {
            sort(s.begin(), s.end());
            ans = s;
        }
        return ans;
    }
};