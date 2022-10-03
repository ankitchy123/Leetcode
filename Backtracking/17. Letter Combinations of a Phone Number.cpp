class Solution
{
public:
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;

    void solve(string digits, int i, string &s)
    {
        if (i == digits.size())
        {
            ans.push_back(s);
            return;
        }
        string str = mp[digits[i]];
        for (int j = 0; j < str.size(); j++)
        {
            s.push_back(str[j]);
            solve(digits, i + 1, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        string s;
        solve(digits, 0, s);
        return ans;
    }
};