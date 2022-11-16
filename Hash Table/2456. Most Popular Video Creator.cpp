class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> mp1;
        unordered_map<string, pair<int, string>> mp2;
        long long numMax = 0;
        for(int i = 0; i < creators.size(); i++)
        {
            mp1[creators[i]] += views[i];
            if(mp2.count(creators[i]))
            {
                if(mp2[creators[i]].first == views[i])
                {
                    mp2[creators[i]].second = min(mp2[creators[i]].second, ids[i]);
                }
                else if(mp2[creators[i]].first < views[i])
                {
                    mp2[creators[i]] = {views[i], ids[i]};
                }
            }
            else{
                mp2[creators[i]] = {views[i], ids[i]};
            }             
            numMax = max(numMax, mp1[creators[i]]);
        }
        vector<vector<string>> ans;
        for(auto i: mp1)
        {
            if(i.second == numMax)
            {
                ans.push_back({i.first, mp2[i.first].second});
            }
        }
        return ans;
    }
};