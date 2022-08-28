class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        stack<pair<int, int>> st;
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top().first <= temp[i])
            {
                st.pop();
            }
            int x = temp[i];
            if (st.empty())
            {
                temp[i] = 0;
            }
            else
            {
                temp[i] = st.top().second - i;
            }
            st.push({x, i});
        }
        return temp;
    }
};