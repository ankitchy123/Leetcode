class Solution
{
public:
    int myAtoi(string s)
    {
        long long ans = 0;
        int i = 0;
        string str = "";
        int sign = 1;
        while (s[i] == ' ' && i < s.size())
        {
            i++;
        }
        if (i < s.size() && s[i] == '+' || s[i] == '-')
        {
            if (s[i] == '-')
            {
                sign = -1;
            }
            i++;
        }
        while (i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign >= INT_MAX)
            {
                return INT_MAX;
            }
            if (ans * sign <= INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }
        return sign * ans;
    }
};