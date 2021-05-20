class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /* Approach 1 : [using simple logic]
        vector<pair<int, int>> mp(arr.size()); //diff : val
        for(int i = 0; i < arr.size(); i++){
            int key = abs(arr[i] - x);
            mp[i].first = key;
            mp[i].second = arr[i];
        }
        vector<int> ans;
        sort(mp.begin(), mp.end());
        for(int i = 0; i < k; i++){
            ans.push_back(mp[i].second);
        }
        sort(ans.begin(), ans.end());
        return ans;
        */
        // Binary Search:
        int start = 0, end = arr.size()-k;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(x - arr[mid] > arr[mid+k] - x)
                start = mid + 1;
            else 
                end = mid;
        }
        return vector<int>(arr.begin()+start, arr.begin()+start+k);
    }
};
