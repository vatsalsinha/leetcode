class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp; // sum%k : index
        mp[0] = -1; // as 0 is also a multiple of k we check whether sum becomes zero for more than i=0.
        // <0,-1> can allow it to return true when the runningSum%k=0,
        
        //for example [1,2,3] is input and k=6
        //then the remainders are [ 1,3,0] i.e runningSum = runningSum%k
        //now 1+2+3=6 which is actually a multiple of 6 and hence 0 should be stored in the hashmap
        
        //why -1?
        //-1 is good for storing for 0 because - it will remove the case where we consider only the first element which alone may be a multiple as 0-(-1) is not greater than 1
        
        // In addition, it also avoids the first element of the array is the multiple of k, since 0-(-1)=1 is not greater than 1.
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            sum %= k;
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
            else
                if(mp.find(sum % k) != mp.end() && i - mp[sum%k] >= 2)
                    return 1;
        }
        return 0;
    }
};
