class Solution {
public:
unordered_map<vector<bool>,int> mp;
    int backtrack(vector<int>& nums,int idx, vector<bool>& isVisited){
        int n=nums.size();
        int res=0;
        if(mp.count(isVisited)) return mp[isVisited];
        for(int i=0;i<n;i++){
            if(isVisited[i]) continue;
            for(int j=i+1;j<n;j++){
                if(isVisited[j]) continue;
                isVisited[i] = isVisited[j] = 1; // visited
                res=max(res,idx*__gcd(nums[i],nums[j])+backtrack(nums,idx + 1,isVisited));
                isVisited[i] = isVisited[j] = 0; // undoing the visit
            }
        }
        return mp[isVisited]=res;
    }
    int maxScore(vector<int>& nums) {
        vector<bool> isVisited(nums.size(), 0);
        return backtrack(nums, 1, isVisited);
    }
};
