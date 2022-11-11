class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> digitLogs, ans;
        vector<pair<string, string>> letterLogs;
        for (int i = 0; i < logs.size(); i++)
        {
            int j = 0;
            while (logs[i][j] != ' ')
            {
                ++j;
            }
            if (isalpha(logs[i][j + 1]))
            {
                letterLogs.emplace_back(logs[i].substr(0, j), logs[i].substr(j + 1));
            }
            else
            {
                digitLogs.push_back(logs[i]);
            }
        }

        sort(letterLogs.begin(), letterLogs.end(), [&](auto &a, auto &b)
             { return a.second == b.second ? a.first < b.first : a.second < b.second; });

        for (int i = 0; i < letterLogs.size(); i++)
        {
            ans.push_back(letterLogs[i].first + " " + letterLogs[i].second);
        }
        for (int i = 0; i < digitLogs.size(); i++)
        {
            ans.push_back(digitLogs[i]);
        }
        return ans;
    }
};