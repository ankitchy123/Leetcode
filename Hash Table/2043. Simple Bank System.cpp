class Bank
{
public:
    unordered_map<int, long long> mp;
    int n;
    Bank(vector<long long> &balance)
    {
        for (int i = 0; i < balance.size(); i++)
        {
            mp[i + 1] = balance[i];
        }
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 > n || account2 > n || mp[account1] < money)
        {
            return false;
        }

        mp[account1] -= money;
        mp[account2] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account > n)
        {
            return false;
        }
        mp[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account > n || money > mp[account])
        {
            return false;
        }
        mp[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */