class Solution
{
public:
    int countCollisions(string directions)
    {
        stack<char> st;
        int ans = 0;

        for (int i = 0; i < directions.size(); i++)
        {
            if (directions[i] == 'L')
            {
                if (!st.empty() and st.top() == 'R')
                {
                    ans += 2;
                    st.pop();
                    st.push('S');
                }
                else if (!st.empty() and st.top() == 'S')
                {
                    ans++;
                    st.push('S');
                }
                else
                {
                    st.push(directions[i]);
                }
            }
            else if (directions[i] == 'R')
            {
                st.push('R');
            }
            else if (directions[i] == 'S')
            {
                if (!st.empty() and st.top() == 'R')
                {
                    ans++;
                    st.pop();
                    st.push('S');
                }
                else
                {
                    st.push('S');
                }
            }
        }
        while (!st.empty())
        {
            char ch = st.top();
            st.pop();
            if (!st.empty())
            {
                if (ch == 'S' && st.top() == 'R')
                {
                    ans++;
                    st.top() = 'S';
                }
                else if (ch == 'L' && st.top() == 'R')
                {
                    st.top() = 'S';
                    ans += 2;
                }
            }
        }
        return ans;
    }
};