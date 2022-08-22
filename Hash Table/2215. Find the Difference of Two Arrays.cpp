class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> m1, m2;
        int i = nums1.size() - 1, j = nums2.size() - 1;
        while (i >= 0 && j >= 0)
        {
            m1[nums1[i]]++;
            m2[nums2[j]]++;
            i--;
            j--;
        }
        while (i >= 0)
        {
            m1[nums1[i]]++;
            i--;
        }
        while (j >= 0)
        {
            m2[nums2[j]]++;
            j--;
        }

        vector<int> vec, vec2;
        for (auto i : m1)
        {
            if (m2.find(i.first) == m2.end())
            {
                vec.push_back(i.first);
            }
        }
        for (auto i : m2)
        {
            if (m1.find(i.first) == m1.end())
            {
                vec2.push_back(i.first);
            }
        }
        return {vec, vec2};
    }
};