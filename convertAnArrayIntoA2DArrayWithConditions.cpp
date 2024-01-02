class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        while(mp.size()){
            vector<int> tmp;
            for(auto it : mp){
                tmp.push_back(it.first);
            }
            for(auto e : tmp){
                if(--mp[e] == 0)
                    mp.erase(e);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
