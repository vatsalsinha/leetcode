class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.begin(), nums1.end());
        double median;
        for(int i = 0; i < nums2.size(); i++){
            res.push_back(nums2[i]);
        }
        sort(res.begin(), res.end());
        int size = res.size();
        if(size%2 == 0){
            median = (res[(size/2) - 1] + res[((size/2) + 1) - 1]) / 2.0;
        }
        else{
            median = res[size/2];
        }
        return median;
    }
};
