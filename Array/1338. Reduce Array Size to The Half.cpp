class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        map<int, int> mp;
        vector<int> vec(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
            vec[mp[arr[i]]]++;
            vec[mp[arr[i]] - 1]--;
        }

        if (vec.size() == 2)
        {
            return 1;
        }

        int sum = arr.size() / 2, ans = 0;
        for (int i = vec.size() - 1; i >= 1; i--)
        {
            if (vec[i] != 0)
            {
                ans += min(vec[i], sum / i + (sum % i == 0 ? 0 : 1));
                sum -= (vec[i] * i);
            }

            if (sum <= 0)
            {
                return ans;
            }
        }

        return 0;
    }
};