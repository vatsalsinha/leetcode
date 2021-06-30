class Solution {
public:
    void flip(vector<int>& arr, int k){
        for(int i = 0; i < k/2; i++)
            swap(arr[i],arr[k-i-1]);
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int k = arr.size();
        for(int i = 0; i < arr.size(); i++){
            auto m = max_element(arr.begin(), arr.end()-i); // find max flip till max element index
            int index = m - arr.begin();
            k = index+1;
            res.push_back(k);
            flip(arr,k);
            k = (arr.size()-i); // flip to end. find new end. for eg 4 ko pehle last me pahochao. fir 3 ko .....
            res.push_back(k);
            flip(arr,k);
        }
        return res;
    }
};
