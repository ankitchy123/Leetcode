class RandomizedCollection
{
public:
    map<int, int> mp;
    vector<int> vec;
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        if (mp[val] <= 0)
        {
            mp[val]++;
            vec.push_back(val);
            return true;
        }
        mp[val]++;
        vec.push_back(val);
        return false;
    }

    bool remove(int val)
    {
        if (mp[val] <= 0)
        {
            return false;
        }

        int count = 0;
        mp[val]--;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == val)
            {
                break;
            }
            count++;
        }
        vec.erase(vec.begin() + count, vec.begin() + count + 1);
        return true;
    }

    int getRandom()
    {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */