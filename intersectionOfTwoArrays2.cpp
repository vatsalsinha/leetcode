class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //without maps
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        // int i = 0, j = 0;
        // vector<int> res;
        // while(i < nums1.size() && j < nums2.size()){
        //     if(nums1[i] == nums2[j]){
        //         res.push_back(nums1[i]);
        //         i++;
        //         j++;
        //     }
        //     else if(nums1[i] > nums2[j])
        //         j++;
        //     else
        //         i++;
        // }
        // return res;
        
        //with maps
        unordered_map<int, int> umap;
        for(auto i : nums1){
            umap[i]++;
        }
        vector<int> res;
        for(auto j : nums2){
            if(umap[j]-- > 0)
                res.push_back(j);
        }
        return res;
    }
};
