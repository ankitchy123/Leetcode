class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq;
        int minVal = INT_MAX;

        for (auto i : nums)
        {
            if (i % 2 == 1)
            {
                i *= 2;
            }
            minVal = min(minVal, i);
            pq.push(i);
        }

        int ans = INT_MAX;
        while (pq.top() % 2 == 0)
        {
            int temp = pq.top();
            pq.pop();
            ans = min(ans, temp - minVal);
            minVal = min(minVal, temp / 2);
            pq.push(temp / 2);
        }
        return min(ans, pq.top() - minVal);
    }
};