class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ']')
            {
                string temp = "";
                while (!st.empty() && st.top() != "[")
                {
                    temp += st.top();
                    st.pop();
                }
                st.pop();

                string num = "";
                while (!st.empty() && st.top() >= "0" && st.top() <= "9")
                {
                    num += st.top();
                    st.pop();
                }

                reverse(num.begin(), num.end());
                int n = stoi(num);
                string ans = "";

                for (int j = 0; j < n; j++)
                {
                    ans += temp;
                }
                st.push(ans);
            }
            else
            {
                string temp = "";
                temp += s[i];
                st.push(temp);
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};