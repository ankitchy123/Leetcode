class Solution
{
public:
    bool check(int mid, vector<int> &price, int k)
    {
        int count = 1, last = price[0];
        for (int i = 1; i < price.size(); i++)
        {
            if (price[i] - last >= mid)
            {
                count++;
                last = price[i];
            }
        }
        return count < k ? false : true;
    }

    int maximumTastiness(vector<int> &price, int k)
    {
        sort(price.begin(), price.end());
        int s = 0, e = price[price.size() - 1] - price[0], ans = INT_MIN;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (check(mid, price, k))
            {
                ans = max(ans, mid);
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};