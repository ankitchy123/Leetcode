class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        vector<vector<string>> res;
        vector<unordered_map<string, int>> table(501);
        set<string> food;
        for (int i = 0; i < orders.size(); i++)
        {
            food.insert(orders[i][2]);
            table[stoi(orders[i][1])][orders[i][2]]++;
        }
        for (int i = 0; i <= 500; i++)
        {
            if (i > 0 && table[i].empty())
            {
                continue;
            }
            vector<string> vec;
            vec.push_back(i == 0 ? "Table" : to_string(i));
            for (auto f : food)
            {
                vec.push_back(i == 0 ? f : to_string(table[i][f]));
            }
            res.push_back(vec);
        }
        return res;
    }
};