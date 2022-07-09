class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        vector<int> vec(58, 0);

        for (int i = 0; i < jewels.size(); i++)
        {
            vec[jewels[i] - 65] = 1;
        }
        int ans = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (vec[stones[i] - 65] == 1)
            {
                ans++;
            }
        }

        return ans;
    }
};