class Solution
{
public:
    bool solve(int i, vector<vector<int>> vec, vector<int> &temp)
    {
        queue<int> q;
        q.push(i);
        temp[i] = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int j = 0; j < vec[curr].size(); j++)
            {
                if (temp[vec[curr][j]] == temp[curr])
                {
                    return false;
                }
                if (temp[vec[curr][j]] == -1)
                {
                    temp[vec[curr][j]] = 1 - temp[curr];
                    q.push(vec[curr][j]);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> vec(n + 1);
        for (int i = 0; i < dislikes.size(); i++)
        {
            vec[dislikes[i][0]].push_back(dislikes[i][1]);
            vec[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> temp(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            if (temp[i] == -1)
            {
                if (!solve(i, vec, temp))
                {
                    return false;
                }
            }
        }
        return true;
    }
};