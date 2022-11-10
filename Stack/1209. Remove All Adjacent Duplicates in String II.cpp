class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty())
            {
                st.push({s[i], 1});
                continue;
            }

            pair<char, int> p = st.top();
            if (p.first == s[i])
            {
                int n = p.second + 1;
                st.pop();
                if (n < k)
                {
                    st.push({s[i], n});
                }
            }
            else
            {
                st.push({s[i], 1});
            }
        }

        string ans = "";
        while (!st.empty())
        {
            int n = st.top().second;
            while (n--)
            {
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};