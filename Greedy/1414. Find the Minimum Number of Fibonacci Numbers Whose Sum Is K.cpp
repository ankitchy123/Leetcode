class Solution
{
public:
    unordered_set<int> st;
    int findMinFibonacciNumbers(int k)
    {
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(1);

        int c1 = 1, c2 = 1;
        while (vec.back() < k)
        {
            int curr = c1 + c2;
            vec.push_back(curr);
            c1 = c2;
            c2 = curr;
        }

        int ans = 0;

        for (int i = vec.size() - 1; i >= 0; i--)
        {
            while (k - vec[i] >= 0)
            {
                ans++;
                k -= vec[i];
            }
        }
        return ans;
    }
};