class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        reverse(popped.begin(), popped.end());
        stack<int> st;

        for (int i = 0; i < pushed.size(); i++)
        {
            if (popped[popped.size() - 1] == pushed[i])
            {
                popped.pop_back();
                while (!st.empty() && st.top() == popped[popped.size() - 1])
                {
                    popped.pop_back();
                    st.pop();
                }
                continue;
            }
            st.push(pushed[i]);
        }

        while (!st.empty() && st.top() == popped[popped.size() - 1])
        {
            popped.pop_back();
            st.pop();
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};