class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mod = 1e9+7;
        unordered_map<int, long> mp;
        long count = 1;
        for(int i = 0; i < arr.size(); i++){
            count = 1;
            for(auto it : mp){
                if(arr[i]%it.first == 0 && mp.find(arr[i]/it.first) != mp.end())
                    count += mp[it.first] * mp[arr[i]/it.first];
            }
            mp[arr[i]] = count;
        }
        long sum = 0;
        for(auto it : mp)
            sum += it.second;
        return sum%mod;
    }
};

// 2 4 5 10
// 2 2 
// 2 5
