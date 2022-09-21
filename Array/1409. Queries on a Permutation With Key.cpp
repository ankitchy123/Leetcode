class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> vec;
        for (int i = m; i >= 1; i--)
        {
            vec.push_back(i);
        }

        int n = vec.size();

        for (int i = 0; i < queries.size(); i++)
        {

            int temp = queries[i];

            auto j = find(vec.begin(), vec.end(), temp);
            queries[i] = n - 1 - (j - vec.begin());
            vec.erase(j);
            vec.push_back(temp);
        }

        return queries;
    }
};