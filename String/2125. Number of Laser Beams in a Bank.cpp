class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        vector<int> vec;
        for (int i = 0; i < bank.size(); i++)
        {
            int temp = 0;
            for (int j = 0; j < bank[i].size(); j++)
            {
                if (bank[i][j] == '1')
                {
                    temp++;
                }
            }
            if (temp > 0)
            {
                vec.push_back(temp);
            }
        }
        if (vec.size() == 0)
        {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < vec.size() - 1; i++)
        {
            ans += vec[i] * vec[i + 1];
        }
        return ans;
    }
};