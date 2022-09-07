class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (mid % 2 == 0)
            {
                if (mid < j && nums[mid] == nums[mid + 1])
                {
                    i = mid + 1;
                }
                else if (mid > i && nums[mid - 1] == nums[mid])
                {
                    j = mid - 1;
                }
                else
                {
                    return nums[mid];
                }
            }
            else
            {
                if (mid > i && nums[mid] == nums[mid - 1])
                {
                    i = mid + 1;
                }
                else if (mid < j && nums[mid + 1] == nums[mid])
                {
                    j = mid - 1;
                }
                else
                {
                    return nums[j];
                }
            }
        }

        return nums[j];
    }
};