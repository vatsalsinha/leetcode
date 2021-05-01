class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> res;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i++]); 
            }
            else{
                res.push_back(nums2[j++]);
            }
        }
        while(i < m){
            res.push_back(nums1[i++]);
        }
        while(j < n){
            res.push_back(nums2[j++]);
        }
        nums1 = res;

        /* approach 2
        int i = m-1, j = n-1, k = m+n-1;
        while(i > -1 && j > -1){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(i > -1){
            nums1[k--] = nums1[i--];
        }
        while(j > -1){
            nums1[k--] = nums2[j--];
        }
        */

        /* approach 3
        int i = n;
        while(i--){
            nums1.pop_back();
        }
        for(int i = 0; i < n; i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        */

        /* approach 4
        int i = m;
        int j = 0;
        while(i < m+n && j < n){
            nums1[i++] = nums2[j++];
        }
        sort(nums1.begin(), nums1.end());
        */
    }
};
