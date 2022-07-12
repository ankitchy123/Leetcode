class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxCan = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            maxCan = max(maxCan, candies[i]);
        }

        vector<bool> ans;

        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= maxCan)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};