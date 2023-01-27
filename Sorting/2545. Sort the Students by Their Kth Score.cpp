class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        int n = score.size();

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back({score[i][k], i});
        }

        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        vector<vector<int>> ans;
        for (int i = 0; i < vec.size(); i++)
        {
            ans.push_back(score[vec[i].second]);
        }
        return ans;
    }
};