class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* BRUTE FORCE approach
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
        */
        //O(log(min(m,n))) approach->
        /*
        If we have L1 > R2, it means there are too many large numbers on the left half of A1, then we must move C1 to the left (i.e. move C2 to the right); 
If L2 > R1, then there are too many large numbers on the left half of A2, and we must move C2 to the left.
Otherwise, this cut is the right one. 
After we find the cut, the medium can be computed as (max(L1, L2) + min(R1, R2)) / 2;
        */
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 < n2)
            return findMedianSortedArrays(nums2,nums1);
        int l = 0, h = n2*2;
        while(l <= h){
            int mid2 = (l + h) / 2;
            int mid1 = n1 + n2 - mid2;
            double l1 = mid1 == 0 ? INT_MIN : nums1[(mid1-1)/2];
            double l2 = mid2 == 0 ? INT_MIN : nums2[(mid2-1)/2];
            double r1 = mid1 == n1*2 ? INT_MAX : nums1[(mid1)/2];
            double r2 = mid2 == n2*2 ? INT_MAX : nums2[(mid2)/2];
            
            if(l1 > r2)
                l = mid2 + 1;
            else if(l2 > r1)
                h = mid2-1;
            else
                return (max(l1,l2) + min(r1,r2))/2;
        }
        return -1;
    }
};