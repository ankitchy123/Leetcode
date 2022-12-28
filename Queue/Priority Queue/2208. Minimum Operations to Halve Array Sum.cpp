class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        priority_queue<double> pq;
        double sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            sum += nums[i];
        }
        double temp = sum / 2.0;
        int ans = 0;
        while (sum > temp)
        {
            double temp2 = pq.top() / 2.0;
            pq.pop();
            pq.push(temp2);
            sum -= temp2;
            ans++;
        }
        return ans;
    }
};