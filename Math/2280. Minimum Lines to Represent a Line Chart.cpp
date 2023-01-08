class Solution
{
public:
    int minimumLines(vector<vector<int>> &stockPrices)
    {
        if (stockPrices.size() == 1)
        {
            return 0;
        }
        sort(stockPrices.begin(), stockPrices.end());
        int ans = 1;
        long double temp = (long double)(stockPrices[1][1] - stockPrices[0][1]) / (stockPrices[1][0] - stockPrices[0][0]);
        for (int i = 2; i < stockPrices.size(); i++)
        {
            long double slope = (long double)(stockPrices[i][1] - stockPrices[i - 1][1]) / (stockPrices[i][0] - stockPrices[i - 1][0]);
            if (temp != slope)
            {
                ans++;
            }
            temp = slope;
        }
        return ans;
    }
};