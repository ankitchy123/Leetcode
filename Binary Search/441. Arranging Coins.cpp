class Solution
{
public:
    int arrangeCoins(int n)
    {
        int i = 1, j = n;

        int ans = 0;
        while (i <= j)
        {
            long mid = i + (j - i) / 2;
            long temp = (mid * (mid + 1)) / 2;

            if (temp <= n)
            {
                i = mid + 1;
                ans = mid;
            }
            else
            {
                j = mid - 1;
            }
        }

        return ans;
    }
};