class Cashier
{
    int temp = 0;

public:
    int k;
    double dis;
    map<int, int> mp;

    Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
    {
        k = n;
        dis = (100.0 - discount) / 100.0;
        for (int i = 0; i < products.size(); i++)
        {
            mp[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount)
    {
        temp++;
        double bill = 0;
        for (int i = 0; i < product.size(); i++)
        {
            bill += (mp[product[i]] * amount[i]);
        }
        if (temp % k == 0)
        {
            bill *= dis;
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */