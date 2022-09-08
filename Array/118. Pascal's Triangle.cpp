class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        ans.push_back({1});

        int i = 1;
        while (numRows > i)
        {
            int j = 1;
            vector<int> vec = {1};
            while (j < ans[i - 1].size())
            {
                vec.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                j++;
            }
            vec.push_back(1);
            ans.push_back(vec);
            i++;
        }
        return ans;
    }
};