class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        while (k--)
        {
            int temp = pq.top();
            temp += 1;
            pq.pop();
            pq.push(temp);
        }

        int mod = 1e9 + 7;
        long long int ans = 1;
        while (!pq.empty())
        {
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        return ans;
    }
};