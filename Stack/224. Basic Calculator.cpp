class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        int ans = 0, sign = 1, num = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '-')
            {
                ans += sign * num;
                num = 0;
                sign = -1;
            }
            else if (s[i] == '+')
            {
                ans += sign * num;
                num = 0;
                sign = 1;
            }
            else if (s[i] == '(')
            {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                ans += sign * num;
                num = 0;
                ans *= st.top();
                st.pop();
                ans += st.top();
                st.pop();
            }
        }
        ans += sign * num;
        return ans;
    }
};