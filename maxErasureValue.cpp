class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st;
        /* 
        The main point here is for the subarray to contain unique elements for each index. Only the first subarrays starting from that index have unique elements.
        */
        for(int i = 0, j = 0, sum = 0; i < nums.size(); i++){
            while(st.find(nums[i]) != st.end()){ // remove elements already present in set.
                st.erase(nums[j]);
                sum -= nums[j];
                j++;
            }
            st.insert(nums[i]);
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

