class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        vector<string> vec;
        map<string, int> mp;
        for (int i = 0; i < cpdomains.size(); i++)
        {
            string num = "";
            int n = 0, m = 0;
            for (int j = 0; j < cpdomains[i].size(); j++)
            {
                if (cpdomains[i][j] >= '0' && cpdomains[i][j] <= '9')
                {
                    num += cpdomains[i][j];
                }
                else if (cpdomains[i][j] == '.' && n == 0)
                {
                    n = j + 1;
                }
                else if (cpdomains[i][j] == '.' && n)
                {
                    m = j + 1;
                    break;
                }
            }
            int x = stoi(num);
            mp[cpdomains[i].substr(num.size() + 1)] += x;
            mp[cpdomains[i].substr(n)] += x;
            if (m)
            {
                mp[cpdomains[i].substr(m)] += x;
            }
        }

        for (auto i : mp)
        {
            vec.push_back(to_string(i.second) + " " + i.first);
        }
        return vec;
    }
};