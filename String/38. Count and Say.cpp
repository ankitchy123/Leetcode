class Solution
{
public:
    string say(string s)
    {
        int i = 0, count;
        string ans = "";
        while (i < s.size())
        {
            count = 1;
            while (s[i] == s[i + 1])
            {
                count++;
                i++;
            }
            ans += to_string(count);
            ans += s[i];
            i++;
        }
        return ans;
    }
    string countAndSay(int n)
    {
        string ans = "1";
        while (1)
        {
            n--;
            if (n == 0)
            {
                return ans;
            }
            ans = say(ans);
            cout << ans << " ";
        }
        return ans;
    }
};