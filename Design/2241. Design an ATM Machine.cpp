class ATM
{
public:
    vector<long long int> atm;
    ATM()
    {
        atm.resize(5, 0);
    }

    void deposit(vector<int> banknotesCount)
    {
        for (int i = 0; i < 5; i++)
        {
            atm[i] += banknotesCount[i];
        }
    }
    vector<int> withdraw(int amount)
    {
        vector<int> notes = {20, 50, 100, 200, 500};
        vector<int> ans(5, 0);
        for (int i = 4; i >= 0; i--)
        {
            if (notes[i] != 0 && amount >= notes[i])
            {
                long long int temp = amount / notes[i];
                temp = min(temp, atm[i]);
                amount -= temp * notes[i];
                ans[i] += temp;
            }
        }
        if (amount == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                atm[i] -= ans[i];
            }
            return ans;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */