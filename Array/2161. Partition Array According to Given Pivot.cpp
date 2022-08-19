class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> ans(nums.size(), 0);
        int low = 0, middle = 0, high = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                middle++;
            }
            else if (nums[i] > pivot)
            {
                high--;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                ans[low] = nums[i];
                low++;
            }
            else if (nums[i] == pivot)
            {
                ans[middle] = nums[i];
                middle++;
            }
            else
            {
                ans[high] = nums[i];
                high++;
            }
        }

        return ans;
    }
};