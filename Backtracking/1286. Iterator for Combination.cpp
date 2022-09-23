class CombinationIterator
{
public:
    vector<string> ans;
    int ind;

    void solve(string characters, string temp, int combinationLength, int k)
    {
        if (k == characters.size())
        {
            if (temp.size() == combinationLength)
            {
                ans.push_back(temp);
            }
            return;
        }

        solve(characters, temp + characters[k], combinationLength, k + 1);
        solve(characters, temp, combinationLength, k + 1);
    }
    CombinationIterator(string characters, int combinationLength)
    {
        ind = 0;
        for (int i = 0; i < characters.length(); i++)
        {
            string temp = "";
            solve(characters, temp + characters[i], combinationLength, i + 1);
        }
    }

    string next()
    {
        return ans[ind++];
    }

    bool hasNext()
    {
        return ind < ans.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */