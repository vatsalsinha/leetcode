class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());
        vector<vector<int>> answer(2);
        for(int i : nums1){
            if(n2.count(i) == 0)
                n2.insert(i), answer[0].push_back(i);
        }
        for(int i : nums2){
            if(n1.count(i) == 0)
                n1.insert(i), answer[1].push_back(i);
        }
        return answer;
    }
};
