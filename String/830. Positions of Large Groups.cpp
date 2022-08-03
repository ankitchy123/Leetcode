class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        vector<vector<int>> ans;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != s[i + 1])
            {
                if (end - start + 1 >= 3)
                {
                    vector<int> vec = {start, end};
                    ans.push_back(vec);
                }
                start = i + 1;
            }
            end++;
        }

        return ans;
    }
};