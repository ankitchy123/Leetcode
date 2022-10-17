class Solution
{
public:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++)
        {
            if (nums[j] < pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (k > nums.size())
        {
            return -1;
        }
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int p = partition(nums, low, high);
            if (p < nums.size() - k)
            {
                low = p + 1;
            }
            else
            {
                high = p - 1;
            }
        }
        return nums[nums.size() - k];
    }
};