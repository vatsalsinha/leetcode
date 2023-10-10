class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> a(st.begin(), st.end());
        int n = nums.size();
        int ans = n;
        for(int i = 0; i < a.size(); i++){
            int left = a[i];
            int right = left + n - 1;
            int pos = upper_bound(a.begin(), a.end(), right) - a.begin();
            int count = pos - i;
            ans = min(ans, n-count); // count elements are already in range; We need n - count numbers.
        }
        return ans;
    }
};
