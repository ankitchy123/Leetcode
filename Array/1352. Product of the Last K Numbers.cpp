class ProductOfNumbers
{
public:
    vector<int> vec;
    int ans = 1;
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        ans *= num;
        if (num == 0)
        {
            vec.clear();
            ans = 1;
        }
        else
        {
            vec.push_back(ans);
        }
    }

    int getProduct(int k)
    {
        int i = vec.size();
        if (k > i)
        {
            return 0;
        }
        else if (k == i)
        {
            return vec[i - 1];
        }
        else
        {
            return vec[i - 1] / vec[i - 1 - k];
        }
    }
};

/**
 * @brief 
 * 
 */
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */