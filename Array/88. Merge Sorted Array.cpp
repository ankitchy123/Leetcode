class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (n && m)
        {
            if (nums1[i] > nums2[j])
            {
                ans.push_back(nums2[j]);
                j++;
                n--;
            }
            else
            {
                ans.push_back(nums1[i]);
                i++;
                m--;
            }
        }

        while (n)
        {
            ans.push_back(nums2[j]);
            j++;
            n--;
        }
        while (m)
        {
            ans.push_back(nums1[i]);
            i++;
            m--;
        }

        nums1 = ans;
    }
};