class Solution {
public:
    void merge(vector<int> &nums, int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r-m;
        int L[n1], R[n2];
        for(int i = 0; i < n1; i++)
            L[i] = nums[l+i];
        for(int i = 0; i < n2; i++)
            R[i] = nums[m+1+i];
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                nums[k] = L[i];
                i++;
            }
            else{
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n1)
            nums[k++] = L[i++];
        while(j < n2)
            nums[k++] = R[j++];
    }
    void mergeSort(vector<int> &nums, int l, int r){
        if(l >= r)
            return;
        int m = l + (r-l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return nums;
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
