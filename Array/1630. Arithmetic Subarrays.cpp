class Solution
{
public:
    bool check(vector<int> nums)
    {
        int temp = nums[1] - nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] != temp)
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++)
        {
            vector<int> nums2(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(nums2.begin(), nums2.end());
            ans.push_back(check(nums2));
        }
        return ans;
    }
};