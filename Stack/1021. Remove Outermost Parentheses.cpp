class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        st.push(s[0]);
        
        string ans = "";
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == '(' && st.empty())
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(st.top() == '(' && st.size() > 1) 
                {
                    st.pop();
                    ans += s[i];
                }
                else
                {
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
                ans += s[i];
            }
        }
        
        return ans;
    }
};