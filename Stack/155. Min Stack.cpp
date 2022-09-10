class MinStack
{
public:
    stack<pair<int, int>> st;
    int m = INT_MAX;
    MinStack()
    {
    }
    void push(int val)
    {
        if (st.empty())
        {
            m = val;
        }
        else
        {
            m = min(m, val);
        }
        st.push({val, m});
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }

        if (st.top().second == m)
        {
            st.pop();
            if (st.empty())
            {
                return;
            }
            m = st.top().second;
        }
        else
        {
            st.pop();
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        return st.top().first;
    }

    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */