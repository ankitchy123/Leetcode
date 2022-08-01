class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {

        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        unordered_map<string, int> mp;
        string word = "";

        for (int i = 0; i < paragraph.size(); i++)
        {
            if (isalpha(paragraph[i]))
            {
                word += paragraph[i];
            }
            else if (paragraph[i] == ' ' || paragraph[i] == ',')
            {
                if (word != "")
                {
                    mp[word]++;
                    word = "";
                }
            }
        }
        mp[word]++;

        for (int i = 0; i < banned.size(); i++)
        {
            mp[banned[i]] = 0;
        }

        string ans = "";
        int n = INT_MIN;
        for (auto &it : mp)
        {
            if (it.second > n)
            {
                ans = it.first;
                n = it.second;
            }
        }
        return ans;
    }
};