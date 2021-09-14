class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // O(n) space
        // vector<int> ans;
        // int n = nums.size();
        // unordered_map<int, int> mp;
        // for(auto n : nums)
        //     mp[n]++;
        // for(auto it : mp)
        //     if(it.second > n/3)
        //         ans.push_back(it.first);
        // return ans;
        
        // o(1) space
        // for an array of length n, there can be atmost 2 elements greater than n/3
        
        int n = nums.size();
        int n1 = -1, n2 = -1, c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            if(n1 == nums[i]){
                c1++;
            }
            else if(n2 == nums[i]){
                c2++;
            }
            else if(c1 == 0){
                n1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0){
                n2 = nums[i];
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        } // till this step we get the value for n1 and n2 which are the possible majority elements. Thus we now calculate the count for n1 and n2
        c1 = 0, c2 = 0;
        for(auto n : nums){
            if(n1 == n)
                c1++;
            else if(n2 == n)
                c2++;
        }
        vector<int> ans;
        if(c1 > n/3)
            ans.push_back(n1);
        if(c2 > n/3)
            ans.push_back(n2);
        return ans;
    }
};
