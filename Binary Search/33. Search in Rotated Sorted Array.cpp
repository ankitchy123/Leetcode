class Solution
{
public:
    int findpivot(vector<int> nums)
    {
        int s = 0, e = nums.size() - 1;
        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] >= nums[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        return s;
    }
    int search(vector<int> &nums, int target)
    {
        int pivot = findpivot(nums);
        int s, e;
        if (target >= nums[pivot] && target <= nums[nums.size() - 1])
        {
            s = pivot;
            e = nums.size() - 1;
        }
        else
        {
            s = 0;
            e = pivot - 1;
        }
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return -1;
    }
};