class Solution {
public:
    bool search(vector<int> arr, int n, int pos){
        int l = 0;
        int r = arr.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == n && pos != mid){
                return true;
            }
            if(arr[mid] < n)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(search(arr, 2*arr[i], i))
                return true;
            
        }
        return false;
    }
};
