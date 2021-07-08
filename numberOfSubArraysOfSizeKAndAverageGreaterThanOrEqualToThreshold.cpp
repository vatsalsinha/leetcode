class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //approach 1 : sliding window
        int count = 0;
        for(int lo = -1, hi = 0, sumWindow = 0; hi < arr.size(); hi++){
            sumWindow += arr[hi];
            if(hi - lo == k){
                if(sumWindow >= k*threshold)
                    count++;
                sumWindow -= arr[++lo];
            }
            
        }
        return count;
        //approach 2 : prefix sum
        // int prefixSum[arr.size()+1];
        // int count = 0;
        // for(int i = 1; i < arr.size()+1; i++)
        //     prefixSum[i] = prefixSum[i-1] + arr[i-1];
        // for(int i = 0; i + k < arr.size()+1; i++){
        //     if(prefixSum[i+k] - prefixSum[i] >= k * threshold)
        //         count++;
        // }
        // return count;
    }
};
