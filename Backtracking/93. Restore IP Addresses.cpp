class Solution
{
public:
    bool isValid(string temp)
    {
        if (temp.size() > 3 || temp.size() == 0)
        {
            return false;
        }
        if (temp.size() > 1 && temp[0] == '0')
        {
            return false;
        }
        if (temp.size() && stoi(temp) > 255)
        {
            return false;
        }
        return true;
    }
    vector<string> ans;
    void solve(string s, int ind, string str, int dots)
    {
        if (dots == 3)
        {
            if (isValid(s.substr(ind)))
            {
                ans.push_back(str + s.substr(ind));
            }
            return;
        }
        for (int i = ind; i < s.size(); i++)
        {
            if (isValid(s.substr(ind, i - ind + 1)))
            {
                str.push_back(s[i]);
                str.push_back('.');
                solve(s, i + 1, str, dots + 1);
                str.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        string str = "";
        solve(s, 0, str, 0);
        return ans;
    }
};