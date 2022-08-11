class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        int count = 0;
        vector<vector<int>> ans;

        for (int i = 1; i < arr.size(); i++)
        {
            count = arr[i] - arr[i - 1];

            if (count < diff)
            {
                diff = count;
                ans.clear();
            }

            if (count == diff)
            {
                vector<int> vec = {arr[i - 1], arr[i]};
                ans.push_back(vec);
            }
        }

        return ans;
    }
};