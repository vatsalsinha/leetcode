class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto it : mp){
            if(mp.find(k-it.first) != mp.end()){
                ans += min(mp[it.first], mp[k-it.first]);
            }
            else if(k == it.first*2){
                ans += floor(mp[it.first]/2);
            }
        }
        return ans/2; // to account for repeated key values
    }
};

/*
1 2 3 4 k = 5
1 : 1
2 : 1
3 : 1
4 : 1
*/
