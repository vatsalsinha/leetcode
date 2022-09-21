class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        vector<int> ans(queries.size());
        int i = 0;
        // get the og even sum from the array
        for(auto n : nums)
            if(n%2 == 0)
                evenSum += n;
        for(auto q : queries){
            // if num[q[1]] is even, remove the element from contributing to the even_sum
            if(nums[q[1]] % 2 == 0)
                evenSum -= nums[q[1]];
            nums[q[1]] += q[0];
            //if num[q[1]] is even, add the element to the even_sum.
            if(nums[q[1]] % 2 == 0)
                evenSum += nums[q[1]];
            ans[i++] = evenSum;
            
        }
        return ans;
    }
};
