class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans(st.size(), '.');
        int i = ans.size() - 1;
        while (!st.empty())
        {
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};