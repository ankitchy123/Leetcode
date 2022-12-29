class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        vector<int> ans;
        int i = 0;
        long long currTime = tasks[0][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        while (i < tasks.size() || !pq.empty())
        {
            if (pq.empty() && currTime < tasks[i][0])
            {
                currTime = tasks[i][0];
            }
            while (i < tasks.size() && currTime >= tasks[i][0])
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            currTime += pq.top().first;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};