class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int i = 0, j = piles.size() - 2;
        int ans = 0;
        while (i < j)
        {
            i++;
            ans += piles[j];
            j -= 2;
        }
        return ans;
    }
};