class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //O(nlogn)
        /*
        vector<int> nums_copy = nums;
        int start = nums.size(), end = 0;
        sort(nums_copy.begin(), nums_copy.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums_copy[i] != nums[i]){
                start = min(start, i);
                end = max(end,i);
            }
        }
        return end-start >= 0 ? end-start+1 : 0;
        */
        //O(n)
        stack<int> st;
        int left=nums.size(), right=0;
        //finding the left most point of the unsorted array
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                left = min(left, st.top());
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        //finding the right most point of the unsorted array
        for(int i = nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                right = max(right, st.top());
                st.pop();
            }
            st.push(i);
        }
        return right-left >=0 ? right-left+1 : 0;
    }
};

// 2 4 6 8 9 10 15
// 2,6,4,8,10,9,15
// 0 1 2 3 4  5 6
