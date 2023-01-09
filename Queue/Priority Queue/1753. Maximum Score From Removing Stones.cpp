class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        int ans = 0;
        while (!pq.empty())
        {
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            if (temp1 == 0 || temp2 == 0)
            {
                break;
            }
            ans++;
            pq.push(temp1 - 1);
            pq.push(temp2 - 1);
        }
        return ans;
    }
};