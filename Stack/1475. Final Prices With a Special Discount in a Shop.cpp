class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<int> st;
        int n = prices.size();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() > prices[i])
            {
                st.pop();
            }
            int x = prices[i];
            if (!st.empty())
            {
                x = x - st.top();
            }

            st.push(prices[i]);
            prices[i] = x;
        }
        return prices;
    }
};