class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        vector<int> ans;
        for(auto m : nums2){
            if(n1.find(m) != n1.end()){
                ans.push_back(m);
                n1.erase(m);
            }
        }
        return ans;
    }
};
