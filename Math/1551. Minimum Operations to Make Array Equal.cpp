class Solution
{
public:
    int minOperations(int n)
    {
        int ans = 0;
        for (int i = 1; i <= ((2 * n) + 1) / 2; i += 2)
        {
            ans += n - i;
        }
        return ans;
    }
};