class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<int>> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0], y = points[i][1];
            pq.push({x * x + y * y, x, y});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < k; ++i)
        {
            vector<int> vec = pq.top();
            pq.pop();
            ans.push_back({vec[1], vec[2]});
        }

        return ans;
    }
};