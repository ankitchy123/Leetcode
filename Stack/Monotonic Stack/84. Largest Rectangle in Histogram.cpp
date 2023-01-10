class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> next(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                next[i] = n;
            }
            else
            {
                next[i] = st.top();
            }
            st.push(i);
        }

        vector<int> prev(n);
        stack<int> st2;
        for (int i = 0; i < n; i++)
        {
            while (!st2.empty() && heights[st2.top()] >= heights[i])
            {
                st2.pop();
            }
            if (st2.empty())
            {
                prev[i] = -1;
            }
            else
            {
                prev[i] = st2.top();
            }
            st2.push(i);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            ans = max(ans, l * b);
        }
        return ans;
    }
};