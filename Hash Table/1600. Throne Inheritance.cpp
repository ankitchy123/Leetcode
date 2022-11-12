class ThroneInheritance
{
public:
    unordered_map<string, vector<string>> children;
    unordered_map<string, bool> dead;
    string king;
    ThroneInheritance(string kingName)
    {
        king = kingName;
    }

    void birth(string parentName, string childName)
    {
        children[parentName].push_back(childName);
    }

    void death(string name)
    {
        dead[name] = true;
    }
    void dfs(string father, vector<string> &ans)
    {
        if (!dead[father])
        {
            ans.push_back(father);
        }
        for (auto child : children[father])
        {
            dfs(child, ans);
        }
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> ans;
        dfs(king, ans);
        return ans;
    }
};

/**
 * @brief 
 * 
 */
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */