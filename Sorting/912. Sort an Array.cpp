class Solution
{
public:
    void merge(vector<int> &nums, int l, int mid, int r)
    {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        int a[n1];
        int b[n2];
        for (int i = 0; i < n1; i++)
        {
            a[i] = nums[l + i];
        }
        for (int i = 0; i < n2; i++)
        {
            b[i] = nums[mid + 1 + i];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (a[i] < b[j])
            {
                nums[k] = a[i];
                i++;
            }
            else
            {
                nums[k] = b[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            nums[k] = a[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            nums[k] = b[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int> &nums, int s, int e)
    {
        if (s < e)
        {
            int mid = s + (e - s) / 2;
            mergeSort(nums, s, mid);
            mergeSort(nums, mid + 1, e);

            merge(nums, s, mid, e);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};