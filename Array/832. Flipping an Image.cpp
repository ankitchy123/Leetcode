class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        for (int i = 0; i < image.size(); i++)
        {
            int n = image[i].size();
            int j = 0, k = n - 1;
            while (j <= k)
            {
                int temp = image[i][k] ^ 1;
                image[i][k] = image[i][j] ^ 1;
                image[i][j] = temp;

                j++;
                k--;
            }
        }

        return image;
    }
};