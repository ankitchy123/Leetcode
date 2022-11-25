class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        stack<int> st;
        long ans = 0;
        int mod = 1000000007;
        for (int i = 0; i <= arr.size(); i++)
        {
            while (!st.empty() && (i == arr.size() || arr[st.top()] > arr[i]))
            {
                int ind = st.top();
                st.pop();
                int left = ind - (st.empty() ? -1 : st.top());
                int right = i - ind;

                ans += (long)(arr[ind] * left * right);
            }
            st.push(i);
        }
        return ans % mod;
    }
};