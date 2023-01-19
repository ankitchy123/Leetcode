class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int prefixMod = 0, ans = 0;
        int sum = 0;
        vector<int> modGroups(k, 0);
        modGroups[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefixMod = sum % k;
            if (prefixMod < 0)
            {
                prefixMod += k;
            }
            ans += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }
        return ans;
    }
};