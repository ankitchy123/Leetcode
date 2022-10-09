/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int ans = 0;
    unordered_map<int, Employee *> mp;
    void solve(int id)
    {
        ans += mp[id]->importance;
        for (int i = 0; i < mp[id]->subordinates.size(); i++)
        {
            solve(mp[id]->subordinates[i]);
        }
    }

    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto i : employees)
        {
            mp[i->id] = i;
        }
        solve(id);
        return ans;
    }
};