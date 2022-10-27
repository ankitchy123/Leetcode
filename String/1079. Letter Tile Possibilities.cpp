class Solution
{
public:
    set<string> s;
    void solve(string tiles, string &str, vector<bool> &visited)
    {
        if (str.size() == tiles.size())
        {
            s.insert(str);
            return;
        }

        for (int i = 0; i < tiles.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                str += tiles[i];
                s.insert(str);
                solve(tiles, str, visited);
                str.pop_back();
                visited[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles)
    {
        vector<bool> visited(tiles.size(), false);
        string str = "";
        solve(tiles, str, visited);
        return s.size();
    }
};