class Solution {
public:
    void merge(vector<int>& count, vector<pair<int,int>>& v, int l, int mid, int r){
        vector<pair<int, int>> tmp(r-l+1);
        int i = l, j = mid+1, k = 0;
        while(i <= mid && j <= r){
            if(v[i].first <= v[j].first){
                tmp[k++] = v[j++];
            }
            else{
                // counting number of elements less than present element to the right
                // remaining part is just regular mergeSort 
                count[v[i].second] += r-j+1;
                tmp[k++] = v[i++];
            }
        }
        while(i <= mid){
            tmp[k++] = v[i++];
        }
        while(j <= r){
            tmp[k++] = v[j++];
        }
        for(int i = l; i < r+1; i++)
            v[i] = tmp[i-l];
    }
    void mergeSort(vector<int>& count, vector<pair<int, int>>& v, int left, int right){
        if(left >= right)
            return;
        int mid = left + (right-left)/2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid+1, right);
        merge(count, v, left, mid, right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size());
        vector<pair<int,int>> v(nums.size());
        for(int i = 0; i < nums.size(); i++){
            v[i] = make_pair(nums[i],i);
        }
        mergeSort(count, v, 0, nums.size()-1);
        return count;
    }
};
