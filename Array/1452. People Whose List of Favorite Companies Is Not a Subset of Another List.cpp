class Solution
{
public:
    bool isSubset(vector<string> &b, vector<string> &a)
    {
        return (includes(a.begin(), a.end(),
                         b.begin(), b.end()));
    }

    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
    {
        int n = favoriteCompanies.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            sort(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
        }

        for (int i = 0; i < n; i++)
        {
            bool isValid = true;

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    if (isSubset(favoriteCompanies[i], favoriteCompanies[j]))
                    {
                        isValid = false;
                        break;
                    }
            }
            if (isValid)
                ans.emplace_back(i);
        }
        return ans;
    }
};