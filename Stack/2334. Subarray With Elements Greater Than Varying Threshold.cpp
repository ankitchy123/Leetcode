class Solution
{
public:
    int validSubarraySize(vector<int> &nums, int threshold)
    {
        vector<int> l(nums.size(), 0), r(nums.size(), 0);
        stack<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                l[i] = -1;
            }
            else
            {
                l[i] = st.top();
            }
            st.push(i);
        }
        int n = nums.size();
        st = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                r[i] = n;
            }
            else
            {
                r[i] = st.top();
            }
            st.push(i);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int k = r[i] - l[i] - 1;
            if (nums[i] > threshold / k)
            {
                return k;
            }
        }
        return -1;
    }
};