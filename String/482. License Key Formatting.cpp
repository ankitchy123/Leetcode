class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string str = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
            {
                continue;
            }
            str += toupper(s[i]);
        }

        if (str.size() == 0)
        {
            return "";
        }

        string ans = "";
        int j = str.size() - 1;

        while (j >= 0)
        {
            int K = k;
            while (K > 0 && j >= 0)
            {
                ans += str[j--];
                K--;
            }
            ans += '-';
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());

        return ans;
    }
};